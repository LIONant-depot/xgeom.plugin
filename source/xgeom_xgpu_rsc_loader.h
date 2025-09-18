#ifndef XGEOM_XGPU_XRSC_GUID_LOADER_H
#define XGEOM_XGPU_XRSC_GUID_LOADER_H
#pragma once
// This header file is used to provide a resource_guid for textures

namespace xrsc
{
    // While this should be just a type... it also happens to be an instance... the instance of the texture_plugin
    // So while generating the type guid we must treat it as an instance.
    inline static constexpr auto    geom_type_guid_v = xresource::type_guid(xresource::guid_generator::Instance64FromString("geom"));
    using                           geom = xresource::def_guid<geom_type_guid_v>;
}

// Now we specify the loader and we must fill in all the information
template<>
struct xresource::loader< xrsc::geom_type_guid_v >
{
    //--- Expected static parameters ---
    constexpr static inline auto         type_name_v = L"geom";                      // This name is used to construct the path to the resource (if not provided)
    using                                data_type = void;
    static data_type* Load(xresource::mgr& Mgr, const full_guid& GUID);
    static void                          Destroy(xresource::mgr& Mgr, data_type&& Data, const full_guid& GUID);
};

#endif