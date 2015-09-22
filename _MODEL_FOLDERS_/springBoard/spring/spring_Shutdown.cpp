                    if(spring_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &spring_NORMALMAP);                                                                  
                            spring_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(spring_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &spring_TEXTUREMAP);                                                                 
                            spring_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(spring_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &spring_VBO);                                                                         
                            spring_VBO  = 0;                                                                                         
                    }                                                                                                              
