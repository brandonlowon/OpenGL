#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    std::string m_filePath; // Debug purposes
    unsigned int m_RendererID;
    // caching for uniforms
    std::unordered_map<std::string, int> m_UniformLocationCache;

public:
    Shader(const std::string filename);
    ~Shader();

   
    void Bind() const;
    void UnBind() const;

    // Set uniforms
    void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);

private:
    ShaderProgramSource ParseShader(const std::string& file);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    unsigned int GetUniformLocation(const std::string& name);
};