                    if(rockRing_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &rockRing_NORMALMAP);                                                                  
                            rockRing_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(rockRing_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &rockRing_TEXTUREMAP);                                                                 
                            rockRing_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(rockRing_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &rockRing_VBO);                                                                         
                            rockRing_VBO  = 0;                                                                                         
                    }                                                                                                              
