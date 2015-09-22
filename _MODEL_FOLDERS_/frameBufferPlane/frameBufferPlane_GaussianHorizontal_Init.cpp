      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      frameBufferPlane_GaussianHorizontal_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_frameBufferPlane_GaussianHorizontal =                                                                                                        

      "    #define highp                                                                                     \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                          \n"                           
      "    varying highp vec2   vTexCoord;                                                                 \n"                           


      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
     
   
     

      "   vec2 Pos;                                                                \n"  
      "   Pos = sign(position.xy);                                                                \n"  
 
      "   gl_Position = vec4(Pos, 0.0, 1.0);                                                                \n"  
        // Image-space
      "   vTexCoord = Pos * 0.5 + 0.5;                                                                     \n"  
     
     
     
      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      frameBufferPlane_GaussianHorizontal_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(frameBufferPlane_GaussianHorizontal_SHADER_VERTEX, 1, &vertexSource_frameBufferPlane_GaussianHorizontal, NULL);                                                                        
      glCompileShader(frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_frameBufferPlane_GaussianHorizontal =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define highp                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    varying highp vec2    vTexCoord;                                                                          \n"                       
      "    const float blurSize = 1.0/200.0;                                                                         \n"                       

     
     
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                                 \n"                       
//==============================================================================================================      
//==============================================================================================================  
      "      vec4 sum = vec4(0.0);                          \n" 
 
      "      sum += texture2D(Texture1, vec2(vTexCoord.x - 4.0*blurSize, vTexCoord.y)) * 0.05;                              \n"   
      "      sum += texture2D(Texture1, vec2(vTexCoord.x - 3.0*blurSize, vTexCoord.y)) * 0.09;                              \n"   
      "    sum += texture2D(Texture1, vec2(vTexCoord.x - 2.0*blurSize, vTexCoord.y)) * 0.12;                              \n"   
      "    sum += texture2D(Texture1, vec2(vTexCoord.x - blurSize,     vTexCoord.y)) * 0.15;                              \n"   
      "    sum += texture2D(Texture1, vec2(vTexCoord.x,                vTexCoord.y)) * 0.16;                              \n"   
      "    sum += texture2D(Texture1, vec2(vTexCoord.x + blurSize,     vTexCoord.y)) * 0.15;                              \n"   
      "   sum += texture2D(Texture1, vec2(vTexCoord.x + 2.0*blurSize, vTexCoord.y)) * 0.12;                              \n"   
      "    sum += texture2D(Texture1, vec2(vTexCoord.x + 3.0*blurSize, vTexCoord.y)) * 0.09;                              \n"   
      "    sum += texture2D(Texture1, vec2(vTexCoord.x + 4.0*blurSize, vTexCoord.y)) * 0.05;                              \n"   
 
      "   gl_FragColor = sum;                              \n"   
//--------------------------------------------------------------------------------------------------------------  


         
//--------------------------------------------------------------------------------------------------------------     
   
    
//==============================================================================================================      
//==============================================================================================================      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT, 1, &fragmentSource_frameBufferPlane_GaussianHorizontal, NULL);                                                                          
      glCompileShader(frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                              
      glAttachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(frameBufferPlane_GaussianHorizontal_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(frameBufferPlane_GaussianHorizontal_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(frameBufferPlane_GaussianHorizontal _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(frameBufferPlane_GaussianHorizontal_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                              
      glDetachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                                            
      glDeleteShader(frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_frameBufferPlane_GaussianHorizontal                   = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_frameBufferPlane_GaussianHorizontal                    = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_frameBufferPlane_GaussianHorizontal               = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_frameBufferPlane_GaussianHorizontal                       = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_frameBufferPlane_GaussianHorizontal                     = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "attenuation");   
      UNIFORM_ratio_Global_2_Component_frameBufferPlane_GaussianHorizontal        = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "ratio_Global_2_Component");        
      UNIFORM_SHADER_SELECTION_frameBufferPlane_GaussianHorizontal                = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "SHADER_SELECTION");        
                                                 
      UNIFORM_TEXTURE_2_frameBufferPlane_GaussianHorizontal                       = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "Texture2");                                              
      UNIFORM_TEXTURE_frameBufferPlane_GaussianHorizontal                         = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
                                                                                                                                 
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "frameBufferPlane_GaussianHorizontal.cpp"                                                                                                                
      glGenBuffers(1,              &frameBufferPlane_GaussianHorizontal_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, frameBufferPlane_GaussianHorizontal_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(frameBufferPlane_GaussianHorizontal), frameBufferPlane_GaussianHorizontal, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
