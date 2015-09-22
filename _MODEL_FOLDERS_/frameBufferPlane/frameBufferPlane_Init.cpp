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
      "    uniform sampler2D       Texture2;                                                                            \n"                       
      
      "    uniform highp float   shininess;                                                                            \n"                       
      "    uniform highp float   attenuation;                                                                          \n"                       
      "    uniform highp float   ratio_Global_2_Component;                                                             \n"                       
      
      "    uniform highp float   SHADER_SELECTION;                                                                          \n"   


      "    varying highp vec4    lightPosition_PASS;                                                                   \n"                       
      "    varying highp vec2    varTexcoord;                                                                          \n"                       

      "     highp  vec4          globalIllumination;                                                                      \n"         
      "     highp  vec4          componentRender;                                                                      \n"       
     
      "     highp  vec4          compositeLayers;                                                                      \n"                       
 
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                                 \n"                       
//==============================================================================================================      
//==============================================================================================================  

//--------------------------------------------------------------------------------------------------------------  
 
      "          // globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "          // componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "         //  compositeLayers        =  mix(globalIllumination, componentRender, ratio_Global_2_Component);                                             \n"       
      "          // gl_FragColor           =  compositeLayers;                                                                           \n"       


//--------------------------------------------------------------------------------------------------------------     
      
    
      "       if(SHADER_SELECTION == 1.0)                                                                                       \n"    
      "       {                                                                                                                   \n"       
      "           globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "           componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "           compositeLayers        =  globalIllumination * componentRender;                                             \n"       
     
      "           gl_FragColor           =  compositeLayers;                                                                           \n"       
      "       }                                                                                                                   \n"  


//--------------------------------------------------------------------------------------------------------------     
      
    
      "       if(SHADER_SELECTION == 2.0)                                                                                       \n"    
      "       {                                                                                                                   \n"       
      "           globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "           componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "           compositeLayers        =  mix(globalIllumination, componentRender, ratio_Global_2_Component);                                             \n"       
      "           gl_FragColor           =  globalIllumination*globalIllumination*componentRender                                       \n"       
      "                                  +  globalIllumination*globalIllumination*componentRender+compositeLayers;                                      \n"         
      
      "       }                                                                                                                   \n"  

    /*
      "       if(SHADER_SELECTION == 2.0)                                                                                       \n"    
      "       {                                                                                                                   \n"       
      "           globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "           componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "           compositeLayers        =  mix(globalIllumination, componentRender, 0.5);                                             \n"       
      "           gl_FragColor           =  compositeLayers;                                                                           \n"       
      "       }                                                                                                                   \n"  
*/
//--------------------------------------------------------------------------------------------------------------     
    
      "       if(SHADER_SELECTION == 3.0)                                                                                       \n"    
      "       {                                                                                                                   \n"   
      "           globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "           componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "           // compositeLayers     =  mix(globalIllumination, componentRender, ratio_Global_2_Component);                       \n"       
      "           compositeLayers        =  globalIllumination * componentRender  * 15;                                                  \n"       
      "           gl_FragColor           =  mix(compositeLayers, componentRender, ratio_Global_2_Component) ;                                \n"                       
      "       }                                                                                                                   \n"  

//--------------------------------------------------------------------------------------------------------------     
     
      "       if(SHADER_SELECTION == 4.0)                                                                                       \n"    
      "       {                                                                                                                   \n"   
      "           globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "           componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "           compositeLayers        =  mix(globalIllumination, componentRender, ratio_Global_2_Component);                       \n"       
      "           //compositeLayers        =   globalIllumination  * componentRender * ratio_Global_2_Component;                                                  \n"       
      "           gl_FragColor           =  compositeLayers;                                                                              \n"                       
      "       }                                                                                                                   \n" 
      
//--------------------------------------------------------------------------------------------------------------     
     
      "       if(SHADER_SELECTION == 5.0)                                                                                       \n"    
      "       {                                                                                                                   \n"   
      "           globalIllumination     = texture2D(Texture1, varTexcoord.st);                                                      \n"   
      "           componentRender        = texture2D(Texture2, varTexcoord.st);                                                        \n"   
      "           compositeLayers        =  mix(globalIllumination, componentRender, 0.34);                                            \n"       
      "           compositeLayers        +=   globalIllumination *ratio_Global_2_Component;                                                  \n"       
      "           gl_FragColor           =  compositeLayers;                                                                              \n"                       
      "       }                                                                                                                   \n" 
            
//--------------------------------------------------------------------------------------------------------------     
   
    
//==============================================================================================================      
//==============================================================================================================      
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
      UNIFORM_ratio_Global_2_Component_frameBufferPlane        = glGetUniformLocation(frameBufferPlane_SHADER,   "ratio_Global_2_Component");        
      UNIFORM_SHADER_SELECTION_frameBufferPlane                = glGetUniformLocation(frameBufferPlane_SHADER,   "SHADER_SELECTION");        
                                                 
      UNIFORM_TEXTURE_2_frameBufferPlane                       = glGetUniformLocation(frameBufferPlane_SHADER,   "Texture2");                                              
      UNIFORM_TEXTURE_frameBufferPlane                         = glGetUniformLocation(frameBufferPlane_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
                                                                                                                                 
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "frameBufferPlane.cpp"                                                                                                                
      glGenBuffers(1,              &frameBufferPlane_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, frameBufferPlane_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(frameBufferPlane), frameBufferPlane, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
