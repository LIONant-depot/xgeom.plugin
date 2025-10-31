
#include "xgeom_compiler.h"
#include "dependencies/xscheduler/source/xscheduler.h"

//---------------------------------------------------------------------------------------

int main( int argc, const char* argv[] )
{
    //
    // Initialize the scheduler system with all hardware threads
    //
    xscheduler::g_System.Init();

    //
   // Create the compiler instance
   //
    auto GeomCompilerPipeline = xgeom_compiler::instance::Create();

    //
    // This is just for debugging
    //
    if constexpr (false)
    {
        static const char* pDebugArgs[] =
        { "TextureCompiler"
        , "-PROJECT"
        , "D:\\LIONant\\xGPU\\example.lionprj"
        , "-DEBUG"
        , "D1"
        , "-DESCRIPTOR"
        , "Descriptors\\Geom\\05\\00\\B2295861246D0005.desc"
        , "-OUTPUT"
        , "D:\\LIONant\\xGPU\\example.lionprj\\Cache\\Resources\\Platforms\\WINDOWS"
        };

        argv = pDebugArgs;
        argc = static_cast<int>(sizeof(pDebugArgs) / sizeof(pDebugArgs[0]));
    }

    //
    // Parse parameters
    //
    if (auto Err = GeomCompilerPipeline->Parse(argc, argv); Err)
    {
        Err.ForEachInChain([&](xerr Error)
        {
            auto Hint = Err.getHint();
            auto String = std::format("Error: {}\n", Err.getMessage());
            printf("%s", String.c_str());
            if (Hint.empty() == false)
                printf("Hint: %s\n", Hint.data());
        });
        return 1;
    }

    //
    // Start compilation
    //
    if (auto Err = GeomCompilerPipeline->Compile(); Err)
    {
        Err.ForEachInChain([&](xerr Error)
        {
            auto Hint = Err.getHint();
            auto String = std::format("Error: {}\n", Err.getMessage());
            printf("%s", String.c_str());
            if (Hint.empty() == false)
                printf("Hint: %s\n", Hint.data());
        });
        return 1;
    }


    return 0;
}

