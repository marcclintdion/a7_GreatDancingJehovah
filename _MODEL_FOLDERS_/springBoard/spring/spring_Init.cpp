      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      spring_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_spring =                                                                                                        

      "    #define highp                                                                                     \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                          \n"                           
      "    varying highp vec2   varTexcoord;                                                                 \n"                           


      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      spring_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(spring_SHADER_VERTEX, 1, &vertexSource_spring, NULL);                                                                        
      glCompileShader(spring_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_spring =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define highp                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                            \n"                       
      "    uniform highp float   attenuation;                                                                          \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                   \n"                       
      "    varying highp vec2    varTexcoord;                                                                          \n"                       

      "     highp  float         NdotL1;                                                                               \n"                       
      "     highp  vec3          normal;                                                                               \n"                       
      "     highp vec3           NormalTex;                                                                            \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                                      \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1 + pow(NdotL1, shininess);      \n"                       
     
     "                               //+  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation                       \n"                       

      "                              // +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);         \n"                       
      
      "         if(gl_FragColor.a == 0)                                                                                                         \n" 
      "         {                                                                                                                               \n"       
      "              gl_FragColor.a          =  texture2D(Texture1, varTexcoord.st, 0.0).r;                                                     \n" 
      "         }                                                                                                                               \n"       
      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      spring_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(spring_SHADER_FRAGMENT, 1, &fragmentSource_spring, NULL);                                                                          
      glCompileShader(spring_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(spring_SHADER, spring_SHADER_VERTEX);                                                                                              
      glAttachShader(spring_SHADER, spring_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(spring_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(spring_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(spring _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(spring_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(spring_SHADER, spring_SHADER_VERTEX);                                                                                              
      glDetachShader(spring_SHADER, spring_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(spring_SHADER_VERTEX);                                                                                                            
      glDeleteShader(spring_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_spring                   = glGetUniformLocation(spring_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_spring                    = glGetUniformLocation(spring_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_spring               = glGetUniformLocation(spring_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_spring                       = glGetUniformLocation(spring_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_spring                     = glGetUniformLocation(spring_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_spring                    = glGetUniformLocation(spring_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_spring                         = glGetUniformLocation(spring_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"spring_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &spring_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, spring_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"spring" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &spring_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, spring_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/springBoard/spring/spring_DOT3.bmp",          spring_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/springBoard/spring/spring.png",               spring_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "spring.cpp"                                                                                                                
      glGenBuffers(1,              &spring_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, spring_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(spring), spring, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
