#include <Common.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


string* ReadShaderFile(string vertPath, string fragPath){
    string vertexCode;
    string fragmentCode;
    ifstream vShaderFile;
    ifstream fShaderFile;

    try{
        // open files
        vShaderFile.open(vertPath);
        fShaderFile.open(fragPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();		
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();	
    }
    catch (std::ifstream::failure& e)
    {
        cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << endl;
    }
    string* retVals = new string[2];
    retVals[0] = vertexCode;
    retVals[1] = fragmentCode;
    return retVals;
}