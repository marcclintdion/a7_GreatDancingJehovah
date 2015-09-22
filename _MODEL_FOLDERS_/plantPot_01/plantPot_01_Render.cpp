                                                                                                
                                                                                            
    glBindBuffer(GL_ARRAY_BUFFER, plantPot_01_VBO);                                                                              
    //-----------------------------------------------------------------------------|__TRANSFORMATIONS                               
    LoadIdentity(modelView);                                                                                                        
    Translate(modelView,   plantPot_01_POSITION[0] + moveSet[0], plantPot_01_POSITION[1] + moveSet[1], plantPot_01_POSITION[2] + moveSet[2]);                              
    Rotate(modelView,      plantPot_01_ROTATE[0], plantPot_01_ROTATE[1], plantPot_01_ROTATE[2], plantPot_01_ROTATE[3]);                                                    
    Scale(modelView, .8, .8, .8);
    //-----------------------------------------------------------------------------|__MATRIX_MATH                                   
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                     
    //------------------------------------------------------------------------------|__LIGHT                                        
    LoadIdentity(lightMatrix);                                                                                                      
    InvertMatrix(lightMatrix, modelView);                                                                                           
        Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);
         Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);
    
    //======================================================================================================                        
    //======================================================================================================   
 
ShaderSelection();

if(SHADER_SELECTION == 0)
{
             #include  "../../_SHADERS/BACKGROUND_SHADER_SELECTION.cpp"  
}    
    
    //======================================================================================================                                                              
    //======================================================================================================                        
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D,  shadowMap_2D);       
    //----------------------------------------------------     
    glActiveTexture(GL_TEXTURE1);                                                                                            
    glBindTexture(GL_TEXTURE_2D,  plantPot_01_NORMAL_TEX);                                                                          
    //----------------------------------------------------                                                                          
    glActiveTexture(GL_TEXTURE0);                                                                                            
    glBindTexture(GL_TEXTURE_2D,  plantPot_01_TEXTURE1);                                                                             
    //-------------------------------------------------------------------------------|__DRAW                                        
    glDrawArrays(GL_TRIANGLES, 0, 804);                                                               

