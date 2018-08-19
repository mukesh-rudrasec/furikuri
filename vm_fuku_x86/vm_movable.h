#pragma once


void vm_mov(vm_context& context) {
    vm_ops_ex_code * ex_code = (vm_ops_ex_code *)&context.vm_code[0];

    uint32_t* dst = get_operand(context, ex_code->info.dst_is_ptr, 1, 2);
    uint32_t* src = get_operand(context, ex_code->info.src_is_ptr, 2, 2);

    memcpy(dst, src, ex_code->info.ops_size);
 
    free_operand(context, 2);

    context.vm_code += sizeof(vm_ops_ex_code);
}

void vm_xchg(vm_context& context) {
    vm_ops_ex_code * ex_code = (vm_ops_ex_code *)&context.vm_code[0];

    uint32_t* dst = get_operand(context, ex_code->info.dst_is_ptr, 1, 2);
    uint32_t* src = get_operand(context, ex_code->info.src_is_ptr, 2, 2);

    uint32_t dst_data;

    memcpy(&dst_data, dst, ex_code->info.ops_size);
    memcpy(dst , src, ex_code->info.ops_size);
    memcpy(src, &dst_data, ex_code->info.ops_size);

    free_operand(context, 2);

    context.vm_code += sizeof(vm_ops_ex_code);
}