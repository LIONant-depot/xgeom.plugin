#ifndef XGEOM_RSC_DESCRIPTOR_H
#define XGEOM_RSC_DESCRIPTOR_H
#pragma once

namespace xgeom_rsc
{
    // While this should be just a type... it also happens to be an instance... the instance of the texture_plugin
    // So while generating the type guid we must treat it as an instance.
    inline static constexpr auto resource_type_guid_v = xresource::type_guid(xresource::guid_generator::Instance64FromString("geom"));

    static constexpr wchar_t mesh_filter_v[]        = L"Mesh\0 *.fbx; *.obj\0Any Thing\0 *.*\0";
    static constexpr wchar_t skeleton_filter_v[]    = L"Skeleton\0 *.fbx\0Any Thing\0 *.*\0";

    struct main
    {
        std::wstring            m_MeshAsset         {};                             // File name of the mesh to load
        std::wstring            m_UseSkeletonFile   {};                             // Use a different skeleton file from the one found in the mesh data
        //            xcore::guid::rcfull<>   m_UseSkeletonResource{};

        XPROPERTY_DEF
        ( "main", main
        , obj_member<"MeshAsset",       &main::m_MeshAsset,         member_ui<std::wstring>::file_dialog<mesh_filter_v,     true, 1>  >
        , obj_member<"UseSkeletonFile", &main::m_UseSkeletonFile,   member_ui<std::wstring>::file_dialog<skeleton_filter_v, true, 1> >
        )
    };
    XPROPERTY_REG(main)

    struct cleanup
    {
        bool                    m_bMergeMeshes          = true;
        std::string             m_RenameMesh            = "Master Mesh";
        bool                    m_bForceAddColorIfNone  = true;
        bool                    m_bRemoveColor          = false;
        std::array<bool, 4>     m_bRemoveUVs            = {};
        bool                    m_bRemoveBTN            = true;
        bool                    m_bRemoveBones          = true;

        XPROPERTY_DEF
        ( "cleanup", cleanup
        , obj_member<"bMergeMeshes",            &cleanup::m_bMergeMeshes >
        , obj_member<"RenameMesh",              &cleanup::m_RenameMesh >
        , obj_member<"bForceAddColorIfNone",    &cleanup::m_bForceAddColorIfNone >
        , obj_member<"bRemoveColor",            &cleanup::m_bRemoveColor >
        , obj_member<"bRemoveUVs",              &cleanup::m_bRemoveUVs >
        , obj_member<"bRemoveBTN",              &cleanup::m_bRemoveBTN >
        , obj_member<"bRemoveBones",            &cleanup::m_bRemoveBones >
        )
    };
    XPROPERTY_REG(cleanup)

    struct lod
    {
        bool                    m_GenerateLODs  = false;
        float                   m_LODReduction  = 0.7f;
        int                     m_MaxLODs       = 5;

        XPROPERTY_DEF
        ("lod", lod
        , obj_member<"GenerateLODs",    &lod::m_GenerateLODs >
        , obj_member<"LODReduction",    &lod::m_LODReduction >
        , obj_member<"MaxLODs",         &lod::m_MaxLODs >
        )
    };
    XPROPERTY_REG(lod)

    struct streams
    {
        bool                    m_UseElementStreams     = false;
        bool                    m_SeparatePosition      = false;
        bool                    m_bCompressPosition     = false;
        bool                    m_bCompressBTN          = true;
        std::array<bool, 4>     m_bCompressUV           {};
        bool                    m_bCompressWeights      = true;

        XPROPERTY_DEF
        ("streams", streams
        , obj_member<"UseElementStreams",       &streams::m_UseElementStreams >
        , obj_member<"SeparatePosition",        &streams::m_SeparatePosition >
        , obj_member<"bCompressPosition",       &streams::m_bCompressPosition >
        , obj_member<"bCompressBTN",            &streams::m_bCompressBTN >
        , obj_member<"bCompressUV",             &streams::m_bCompressUV >
        , obj_member<"bCompressWeights",        &streams::m_bCompressWeights >
        )
    };
    XPROPERTY_REG(streams)

    struct descriptor : xresource_pipeline::descriptor::base
    {
        using parent = xresource_pipeline::descriptor::base;


        void SetupFromSource(std::string_view FileName) override
        {
        }

        void Validate(std::vector<std::string>& Errors) const noexcept override
        {
        }

        XPROPERTY_VDEF
        ("Geom", descriptor
        , obj_member<"Main",        &descriptor::m_Main >
        , obj_member<"Cleanup",     &descriptor::m_Cleanup >
        , obj_member<"LOD",         &descriptor::m_LOD >
        , obj_member<"Streams",     &descriptor::m_Streams >
        )

        main        m_Main;
        cleanup     m_Cleanup;
        lod         m_LOD;
        streams     m_Streams;
    };
    XPROPERTY_VREG(descriptor)


    //--------------------------------------------------------------------------------------

    struct factory final : xresource_pipeline::factory_base
    {
        using xresource_pipeline::factory_base::factory_base;

        std::unique_ptr<xresource_pipeline::descriptor::base> CreateDescriptor(void) const noexcept override
        {
            return std::make_unique<descriptor>();
        };

        xresource::type_guid ResourceTypeGUID(void) const noexcept override
        {
            return resource_type_guid_v;
        }

        const char* ResourceTypeName(void) const noexcept override
        {
            return "Geom";
        }

        const xproperty::type::object& ResourceXPropertyObject(void) const noexcept override
        {
            return *xproperty::getObjectByType<descriptor>();
        }
    };

    inline static factory g_Factory{};
}
#endif