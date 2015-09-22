                    if(foliageRockRing_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &foliageRockRing_NORMALMAP);                                                                  
                            foliageRockRing_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(foliageRockRing_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &foliageRockRing_TEXTUREMAP);                                                                 
                            foliageRockRing_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(foliageRockRing_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &foliageRockRing_VBO);                                                                         
                            foliageRockRing_VBO  = 0;                                                                                         
                    }                                                                                                              
