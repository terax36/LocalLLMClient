#pragma once

// Keep this header free of C++ standard library dependencies.
// Xcode Cloud's clang dependency scanning has been flaky when stdlib headers
// are included through Swift/Clang module boundaries.

struct common_chat_templates;
struct common_chat_templates_inputs;
struct common_chat_params;
struct llama_model;

// Wrapper functions for Swift C++ interop
common_chat_templates_inputs* create_chat_templates_inputs();
void add_message_to_inputs(common_chat_templates_inputs* inputs, const char* role, const char* content);
common_chat_params apply_chat_templates_safe(const common_chat_templates* tmpls, common_chat_templates_inputs* inputs);
common_chat_params apply_chat_templates_with_model(const struct llama_model* model, common_chat_templates_inputs* inputs);
void free_chat_templates_inputs(common_chat_templates_inputs* inputs);
