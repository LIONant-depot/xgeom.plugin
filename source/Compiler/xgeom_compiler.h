#ifndef XGEOM_COMPILER_H
#define XGEOM_COMPILER_H
#pragma once

#include "dependencies/xresource_pipeline_v2/source/xresource_pipeline.h"

namespace xgeom_compiler
{
    enum class state : std::uint32_t
    { OK
    , FAILURE
    };

    struct instance : xresource_pipeline::compiler::base
    {
        static std::unique_ptr<instance> Create(void);
    };
}

#endif