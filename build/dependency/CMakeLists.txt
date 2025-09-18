include(${CMAKE_BINARY_DIR}/_deps/xcmake_tools/Common.cmake)

# Fetch dependencies
FetchAndPopulate("https://github.com/LIONant-depot/xbits.git" "main")
FetchAndPopulate("https://github.com/LIONant-depot/xserializer.git" "main")
FetchAndPopulate("https://github.com/LIONant-depot/xraw3d.git" "main")
FetchAndPopulate("https://github.com/LIONant-depot/xresource_pipeline_v2.git" "main")
FetchAndPopulate("https://github.com/LIONant-depot/xstrtool.git" "main" )
FetchAndPopulate("https://github.com/zeux/meshoptimizer.git" "master")
FetchAndPopulate("https://github.com/LIONant-depot/xscheduler.git" "main")

# Define meshoptimizer
DefineInterfaceComponent(meshoptimizer "dependencies"
  "src/meshoptimizer.h"
  "**Implementation"
  "src/vcacheoptimizer.cpp"
  "src/vfetchoptimizer.cpp"
  "src/allocator.cpp"
  "src/clusterizer.cpp"
  "src/indexanalyzer.cpp"
  "src/indexcodec.cpp"
  "src/indexgenerator.cpp"
  "src/overdrawoptimizer.cpp"
  "src/partition.cpp"
  "src/quantization.cpp"
  "src/rasterizer.cpp"
  "src/simplifier.cpp"
  "src/spatialorder.cpp"
  "src/stripifier.cpp"
  "src/vertexcodec.cpp"
  "src/vertexfilter.cpp"
)

# Define xtexture_compiler
DefineInterfaceComponent(xgeom_compiler_ "dependencies"
  "source/xgeom_rsc_descriptor.h"
  "source/xgeom.h"
  "source/Compiler/xgeom_compiler.cpp"
  "source/Compiler/xgeom_compiler.h"
)
