    chestArmor_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_chestArmor =                                                                                    

    " #define lowp                                                                                                       \n" 
    
    "     attribute vec4 vertex_01;                                                                                      \n" 
    "     attribute vec2 texture;                                                                                        \n" 
    
    "     uniform   lowp vec4 light_POSITION_01;                                                                         \n" 
    "     uniform        mat4 ModelView;                                                                                 \n" 
    "     uniform        mat4 ModelViewProjection;                                                                       \n" 
    "     uniform        mat4 ModelViewProjectionInverse;                                                                \n" 
    "     uniform        mat4 LightMatrix;                                                                               \n" 
 
    " //-------------------------------------------------                                                                \n" 

    "     varying lowp   vec4 lightPosition_PASS;                                                                        \n" 
    "     varying lowp   vec2 varTexcoord;                                                                               \n" 
    " //-------------------------------------------------                                                                \n" 
    " void main()                                                                                                        \n" 
    " {                                                                                                                  \n" 
    "     varTexcoord             = texture;                                                                             \n" 

    "     lightPosition_PASS      = normalize(LightMatrix * light_POSITION_01);                                          \n" 
    "     gl_Position             = ModelViewProjection * vertex_01;                                                     \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_chestArmor =                                                                                  

    "#ifdef GL_ES                                                                                                        \n" 
    "#else                                                                                                               \n" 
    "#define lowp                                                                                                        \n" 
    "#endif                                                                                                              \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                    \n" 

    "    uniform sampler2D  Texture1;                                                                                    \n" 
    "    uniform sampler2D  NormalMap;                                                                                   \n" 

    "                                                                                  //uniform lowp  float counter;    \n" 
    "   //--------------------------------------------                                                                   \n" 
    "    varying lowp vec4  lightPosition_PASS;                                                                          \n" 
    "    varying lowp vec2  varTexcoord;                                                                                 \n" 

    "    //--------------------------------------------                                                                  \n" 
    "            lowp vec4  tempColor;                                                                                   \n" 
    "            lowp vec3  NormalTex;                                                                                   \n" 

    "            //------------------------                                                                              \n" 
    "            lowp float NdotL1;                                                                                      \n" 
    "//---------------------------------------------------------------------------------------MAIN                       \n" 

    "void main()                                                                                                         \n" 
    "{                                                                                                                   \n" 
    "            //----------------------------------------------------------------------------                          \n" 
    "            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                           \n" 
    "            NormalTex       =  normalize((NormalTex  - 0.5)*2.0);                                                   \n" 
    "            NdotL1          =  dot(NormalTex, lightPosition_PASS.xyz);                                              \n" 

    "            tempColor       =  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1* NdotL1                            \n"
    "                              + pow(NdotL1, 70.0)*4.0*texture2D(Texture1, varTexcoord.st, 0.0);                      \n" 

    "            gl_FragColor    =  tempColor;                                                                           \n" 

    "}                                                                                                                   \n";
        //--------------------------------------------------------------------------------------------------                    

        chestArmor_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( chestArmor_SHADER_VERTEX, 1, &vertexSource_chestArmor, NULL );                                        
        glCompileShader( chestArmor_SHADER_VERTEX);                                                                            
        //----------------------------------------------------                                                                  
        chestArmor_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( chestArmor_SHADER_FRAGMENT, 1, &fragmentSource_chestArmor, NULL );                                    
        glCompileShader(chestArmor_SHADER_FRAGMENT);                                                                           
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( chestArmor_SHADER, chestArmor_SHADER_VERTEX );                                                        
        glAttachShader( chestArmor_SHADER, chestArmor_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(chestArmor_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(chestArmor_SHADER,   1, "normal");                                                            
        glBindAttribLocation(chestArmor_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( chestArmor_SHADER_VERTEX);                                                                             
        glDeleteShader( chestArmor_SHADER_FRAGMENT);                                                                           
        glLinkProgram(chestArmor_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_chestArmor               = glGetUniformLocation(chestArmor_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_chestArmor           = glGetUniformLocation(chestArmor_SHADER, "ModelViewProjection");        
        UNIFORM_MODELVIEWPROJ_INVERSE_chestArmor   = glGetUniformLocation(chestArmor_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_chestArmor            = glGetUniformLocation(chestArmor_SHADER, "LightMatrix");                
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_chestArmor       = glGetUniformLocation(chestArmor_SHADER, "light_POSITION_01");          
        //-----------------------------                                                                                         
         UNIFORM_TEXTURE_DOT3_chestArmor           = glGetUniformLocation(chestArmor_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_chestArmor                 = glGetUniformLocation(chestArmor_SHADER, "Texture1");                   

        //------------------------------------------------------------------------------------------------------------------------      

        loadTexture("_MODEL_FOLDERS_/chestArmor/chestArmor_DOT3.bmp",                       chestArmor_NORMAL_TEX);                
        loadTexture("_MODEL_FOLDERS_/chestArmor/chestArmor.jpg",                            chestArmor_TEXTURE1);                  
        //------------------------------------------------------------------------------------------|___LOAD_VBO                        
        #include    "chestArmor.cpp"                                                                                           
        glGenBuffersARB(1,              &chestArmor_VBO);                                                                              
        glBindBufferARB(GL_ARRAY_BUFFER, chestArmor_VBO);                                                                              
        glBufferDataARB(GL_ARRAY_BUFFER, sizeof(chestArmor), chestArmor, GL_STATIC_DRAW);                                             
        glBindBufferARB(GL_ARRAY_BUFFER, 0);                                                                                            

