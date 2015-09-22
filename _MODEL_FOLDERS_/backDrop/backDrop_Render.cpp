                                                                                             
    //-----------------------------                                                                                                       
    glBindBuffer(GL_ARRAY_BUFFER, backDrop_VBO);                                                                                       
    //-----------------------------------------------------------------------------|__TRANSFORMATIONS                                     
    LoadIdentity(modelView);                                                                                                              
    Translate(modelView,   backDrop_POSITION[0], backDrop_POSITION[1], backDrop_POSITION[2]);      
    Rotate(modelView,      backDrop_ROTATE[0], backDrop_ROTATE[1], backDrop_ROTATE[2], backDrop_ROTATE[3]);                               
    //Scale(modelView,     backDrop_SCALE,       backDrop_SCALE, backDrop_SCALE);                                                         
    //-----------------------------------------------------------------------------|__MATRIX_MATH                                         
    MultiplyMatrix(mvpMatrix , projection, modelView);                                                                           
    //InvertMatrix(ModelViewProjectionInverse, mvpMatrix);                                                                      
    //------------------------------------------------------------------------------|__LIGHT                                              
    LoadIdentity(lightMatrix);                                                                                                            
    InvertMatrix(lightMatrix, modelView);                                                                                                 
    //Translate(lightMatrix,   backDrop_LIGHT_POSITION[0], backDrop_LIGHT_POSITION[1], backDrop_LIGHT_POSITION[2]);                       
    //Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                             
    //======================================================================================================                              
    
ShaderSelection();    

if(SHADER_SELECTION == 0)
{
       
    #include  "../../_SHADERS/BACKGROUND/backDrop_RENDER.cpp"                                                                        
}    
    
    
    //======================================================================================================                                                                                                            
    glActiveTexture(GL_TEXTURE0);                                                                                                      
    glBindTexture(GL_TEXTURE_2D, backDrop_TEXTURE1);                                                                                      
    //-------------------------------------------------------------------------------|__DRAW                                              
    glDrawArrays(GL_TRIANGLES, 0, 6);                                                                     

