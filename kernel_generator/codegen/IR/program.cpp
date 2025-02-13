#include "program.hpp"

using namespace codegen::ir;

BasicBlock::Pointer Program::create_empty_bb()
{
    codegen::ir::BasicBlock::Pointer emptybb(new codegen::ir::BasicBlock);
    this->push_back(emptybb);
    return emptybb;
}

Program Program::create_single_basic_block_program()
{
    Program prog{std::make_shared<BasicBlock>()};
    return prog;
}

Program::Program(std::initializer_list<BasicBlock::Pointer> bblist)
{
    this->insert(this->end(), bblist.begin(), bblist.end());
}

BasicBlock::Pointer BasicBlock::get_next()
{
    return next;
}

BasicBlock::Pointer BasicBlock::get_prior()
{
    return prior;
}

BasicBlock::Pointer Program::get_entry()
{
    if (entry != nullptr)
        return entry;
    for (auto& i : *this)
    {
        if (i->get_prior() == nullptr)
        {
            if (entry != nullptr)
                codegen_LOG(codegen_WARNING)
                    << "Several entry basic blocks in Program: We only support fist one.";
            entry = i;
        }
    }
    if (entry == nullptr)
        codegen_LOG(codegen_WARNING) << "Program has no entry basic block.";
    return entry;
}

BasicBlock::Pointer Program::get_exit()
{
    if (exit != nullptr)
        return exit;
    for (auto& i : *this)
    {
        if (i->get_next() == nullptr)
        {
            if (exit != nullptr)
                codegen_LOG(codegen_WARNING)
                    << "Several exit basic blocks in Program: We only support fist one.";
            exit = i;
        }
    }
    if (exit == nullptr)
        codegen_LOG(codegen_WARNING) << "Program has no exit basic block.";
    return exit;
}