                    if(frameBufferPlane_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &frameBufferPlane_NORMALMAP);                                                                  
                            frameBufferPlane_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(frameBufferPlane_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &frameBufferPlane_TEXTUREMAP);                                                                 
                            frameBufferPlane_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(frameBufferPlane_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &frameBufferPlane_VBO);                                                                         
                            frameBufferPlane_VBO  = 0;                                                                                         
                    }                                                                                                              
