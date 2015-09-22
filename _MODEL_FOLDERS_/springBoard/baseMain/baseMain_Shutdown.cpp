                    if(baseMain_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &baseMain_NORMALMAP);                                                                  
                            baseMain_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(baseMain_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &baseMain_TEXTUREMAP);                                                                 
                            baseMain_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(baseMain_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &baseMain_VBO);                                                                         
                            baseMain_VBO  = 0;                                                                                         
                    }                                                                                                              
