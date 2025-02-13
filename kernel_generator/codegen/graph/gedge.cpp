#include <sstream>

#include "gedge.hpp"

using namespace codegen::graph;

std::string codegen::graph::Edge::DebugString() const
{
    std::stringstream ss;
    ss << "[id=" << m_id << " " << m_src->get_name().c_str() << ":" << m_src_output << " -> "
       << m_dst->get_name().c_str() << ":" << m_dst_input << "]";
    return ss.str();
}
