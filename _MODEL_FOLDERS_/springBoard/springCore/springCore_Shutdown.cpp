                    if(springCore_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &springCore_NORMALMAP);                                                                  
                            springCore_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(springCore_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &springCore_TEXTUREMAP);                                                                 
                            springCore_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(springCore_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &springCore_VBO);                                                                         
                            springCore_VBO  = 0;                                                                                         
                    }                                                                                                              
