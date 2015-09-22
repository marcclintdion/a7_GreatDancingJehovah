GLuint      head_SHADER_VERTEX;                                                                                                      
GLuint      head_SHADER_FRAGMENT;                                                                                                    
GLuint      head_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_head;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_head;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_head;                                                                                          
GLuint      UNIFORM_SHININESS_head;                                                                                                  
GLuint      UNIFORM_ATTENUATION_head;    
GLuint      UNIFORM_TEXTURE_DOT3_head;                                                                                               
GLuint      UNIFORM_TEXTURE_head;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     head_POSITION[]            = { 0.0, 0.359999, -0.004, 1.0};                                                                    
                                                                 
GLfloat     head_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
  GLfloat     head_LIGHT_POSITION_01[] = {2, -15.0, 30, 1};
  GLfloat     head_ATTENUATION         =  0.94;
  GLfloat     head_SHININESS           =  80;                                                                                   
//-----------------------------------------------------------------                                                                       
GLuint      head_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
