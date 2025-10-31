#if 0
#include "xgeom_xgpu_rsc_loader.h"
#include "xgeom.h"
//#include "dependencies/xresource_guid/source/"
#include "dependencies/xresource_guid/source/bridges/xresource_xproperty_bridge.h"

//
// We will register the loader, the properties, 
//
inline static auto s_GeomRegistrations = xresource::common_registrations<xrsc::geom_type_guid_v>{};

//------------------------------------------------------------------

xresource::loader< xrsc::geom_type_guid_v >::data_type* xresource::loader< xrsc::geom_type_guid_v >::Load(xresource::mgr& Mgr, const full_guid& GUID)
{
    auto&           UserData    = Mgr.getUserData<resource_mgr_user_data>();
    std::wstring    Path        = Mgr.getResourcePath(GUID, type_name_v);
    xgeom*          pGeom       = nullptr;

    // Load the xbitmap
    xserializer::stream Stream;
    if (auto Err = Stream.Load(Path, pGeom); Err)
    {
        assert(false);
    }


    // Free the bitmap
    xserializer::default_memory_handler_v.Free(xserializer::mem_type{ .m_bUnique = true }, pBitmap);

    // Return the texture
    return Texture.release();
}

//------------------------------------------------------------------

void xresource::loader< xrsc::geom_type_guid_v >::Destroy(xresource::mgr& Mgr, data_type&& Data, const full_guid& GUID)
{
    auto& UserData = Mgr.getUserData<resource_mgr_user_data>();

    UserData.m_Device.Destroy(std::move(Data));

    // Free the resource
    xserializer::default_memory_handler_v.Free(xserializer::mem_type{ .m_bUnique = true }, &Data);
}

#endif