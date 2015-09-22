                    if(facing_VIEW_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &facing_VIEW_NORMALMAP);                                                                  
                            facing_VIEW_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(facing_VIEW_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &facing_VIEW_TEXTUREMAP);                                                                 
                            facing_VIEW_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(facing_VIEW_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &facing_VIEW_VBO);                                                                         
                            facing_VIEW_VBO  = 0;                                                                                         
                    }                                                                                                              
                    if(facing_VIEW_INDICES_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &facing_VIEW_INDICES_VBO);                                                                         
                            facing_VIEW_INDICES_VBO  = 0;                                                                                         
                    }                                                                                                              
