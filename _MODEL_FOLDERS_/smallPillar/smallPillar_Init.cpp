                 

        //---------------------------------------------------------------------------------------------------------------------      
#ifdef WIN32
        loadTexture("_MODEL_FOLDERS_/smallPillar/smallPillar_DOT3.bmp",                       smallPillar_NORMAL_TEX);                
        loadTexture("_MODEL_FOLDERS_/smallPillar/smallPillar.jpg",                            smallPillar_TEXTURE1);
#endif                          
        //---------------------------------------------------------------------------------------------------------------------|___LOAD_VBO                        
        #include    "smallPillar.cpp"                                                                                           
        glGenBuffers(1,              &smallPillar_VBO);                                                                              
        glBindBuffer(GL_ARRAY_BUFFER, smallPillar_VBO);                                                                              
        glBufferData(GL_ARRAY_BUFFER, sizeof(smallPillar), smallPillar, GL_STATIC_DRAW);                                             
        glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                            

