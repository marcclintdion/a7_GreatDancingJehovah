                    if(lightDiskobj_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &lightDiskobj_NORMALMAP);                                                                  
                            lightDiskobj_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(lightDiskobj_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &lightDiskobj_TEXTUREMAP);                                                                 
                            lightDiskobj_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(lightDiskobj_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &lightDiskobj_VBO);                                                                         
                            lightDiskobj_VBO  = 0;                                                                                         
                    }                                                                                                              
                    if(lightDiskobj_INDICES_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &lightDiskobj_INDICES_VBO);                                                                         
                            lightDiskobj_INDICES_VBO  = 0;                                                                                         
                    }                                                                                                              
