#pragma once

#include <memory>
#include <vector>

namespace codegen
{
    namespace graph
    {
        class GNode;

        class GNodeVector : public std::vector<std::shared_ptr<GNode>>
        {
        public:
            GNodeVector(const std::initializer_list<std::shared_ptr<GNode>>& gnodes)
                : std::vector<std::shared_ptr<GNode>>(gnodes)
            {
            }

            GNodeVector(const std::vector<std::shared_ptr<GNode>>& gnodes)
                : std::vector<std::shared_ptr<GNode>>(gnodes)
            {
            }

            GNodeVector(const GNodeVector& gnodes)
                : std::vector<std::shared_ptr<GNode>>(gnodes)
            {
            }

            GNodeVector(size_t size)
                : std::vector<std::shared_ptr<GNode>>(size)
            {
            }

            GNodeVector& operator=(const GNodeVector& other) = default;

            GNodeVector() {}
        };
    }
}
