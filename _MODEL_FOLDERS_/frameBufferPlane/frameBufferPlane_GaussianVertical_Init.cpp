      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      frameBufferPlane_GaussianVertical_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_frameBufferPlane_GaussianVertical =                                                                                                        

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
      frameBufferPlane_GaussianVertical_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(frameBufferPlane_GaussianVertical_SHADER_VERTEX, 1, &vertexSource_frameBufferPlane_GaussianVertical, NULL);                                                                        
      glCompileShader(frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_frameBufferPlane_GaussianVertical =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define highp                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    varying highp vec2    vTexCoord;                                                                          \n"                       
      "    const float blurSize = 1.0/100.0;                                                                         \n"                       

     
     
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                                 \n"                       
//==============================================================================================================      
//==============================================================================================================  
      "      vec4 sum = vec4(0.0);                          \n" 
 
  // blur in y (vertical)
   // take nine samples, with the distance blurSize between them
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y - 4.0*blurSize)) * 0.05;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y - 3.0*blurSize)) * 0.09;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y - 2.0*blurSize)) * 0.12;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y - blurSize)) * 0.15;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y + blurSize)) * 0.15;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y + 2.0*blurSize)) * 0.12;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y + 3.0*blurSize)) * 0.09;      \n" 
      "    sum += texture2D(Texture1, vec2(vTexCoord.x, vTexCoord.y + 4.0*blurSize)) * 0.05;      \n" 
 
      "   gl_FragColor = sum;                              \n"   
//--------------------------------------------------------------------------------------------------------------  


         
//--------------------------------------------------------------------------------------------------------------     
   
    
//==============================================================================================================      
//==============================================================================================================      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      frameBufferPlane_GaussianVertical_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(frameBufferPlane_GaussianVertical_SHADER_FRAGMENT, 1, &fragmentSource_frameBufferPlane_GaussianVertical, NULL);                                                                          
      glCompileShader(frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                              
      glAttachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(frameBufferPlane_GaussianVertical_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(frameBufferPlane_GaussianVertical_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(frameBufferPlane_GaussianVertical _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(frameBufferPlane_GaussianVertical_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                              
      glDetachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                                            
      glDeleteShader(frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_frameBufferPlane_GaussianVertical                   = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_frameBufferPlane_GaussianVertical                    = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_frameBufferPlane_GaussianVertical               = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_frameBufferPlane_GaussianVertical                       = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_frameBufferPlane_GaussianVertical                     = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "attenuation");   
      UNIFORM_ratio_Global_2_Component_frameBufferPlane_GaussianVertical        = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "ratio_Global_2_Component");        
      UNIFORM_SHADER_SELECTION_frameBufferPlane_GaussianVertical                = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "SHADER_SELECTION");        
                                                 
      UNIFORM_TEXTURE_2_frameBufferPlane_GaussianVertical                       = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "Texture2");                                              
      UNIFORM_TEXTURE_frameBufferPlane_GaussianVertical                         = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
                                                                                                                                 
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "frameBufferPlane_GaussianVertical.cpp"                                                                                                                
      glGenBuffers(1,              &frameBufferPlane_GaussianVertical_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, frameBufferPlane_GaussianVertical_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(frameBufferPlane_GaussianVertical), frameBufferPlane_GaussianVertical, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
