      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      frameBufferPlane_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_frameBufferPlane =                                                                                                        

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
      frameBufferPlane_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(frameBufferPlane_SHADER_VERTEX, 1, &vertexSource_frameBufferPlane, NULL);                                                                        
      glCompileShader(frameBufferPlane_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_frameBufferPlane =                                                                                                            

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

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .2                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      frameBufferPlane_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(frameBufferPlane_SHADER_FRAGMENT, 1, &fragmentSource_frameBufferPlane, NULL);                                                                          
      glCompileShader(frameBufferPlane_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(frameBufferPlane_SHADER, frameBufferPlane_SHADER_VERTEX);                                                                                              
      glAttachShader(frameBufferPlane_SHADER, frameBufferPlane_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(frameBufferPlane_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(frameBufferPlane_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(frameBufferPlane _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(frameBufferPlane_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(frameBufferPlane_SHADER, frameBufferPlane_SHADER_VERTEX);                                                                                              
      glDetachShader(frameBufferPlane_SHADER, frameBufferPlane_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(frameBufferPlane_SHADER_VERTEX);                                                                                                            
      glDeleteShader(frameBufferPlane_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_frameBufferPlane                   = glGetUniformLocation(frameBufferPlane_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_frameBufferPlane                    = glGetUniformLocation(frameBufferPlane_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_frameBufferPlane               = glGetUniformLocation(frameBufferPlane_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_frameBufferPlane                       = glGetUniformLocation(frameBufferPlane_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_frameBufferPlane                     = glGetUniformLocation(frameBufferPlane_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_frameBufferPlane                    = glGetUniformLocation(frameBufferPlane_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_frameBufferPlane                         = glGetUniformLocation(frameBufferPlane_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"frameBufferPlane_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &frameBufferPlane_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, frameBufferPlane_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"frameBufferPlane" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &frameBufferPlane_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, frameBufferPlane_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_DOT3.bmp",          frameBufferPlane_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane.png",               frameBufferPlane_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "frameBufferPlane.cpp"                                                                                                                
      glGenBuffers(1,              &frameBufferPlane_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, frameBufferPlane_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(frameBufferPlane), frameBufferPlane, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
