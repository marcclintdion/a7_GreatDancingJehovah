
  
    glBindBuffer(GL_ARRAY_BUFFER, tile_2m_VBO);   
    //-----------------------------------------------------------------------------|__TRANSFORMATIONS 
    LoadIdentity(modelView);
    Translate(modelView,   tile_2m_POSITION[0] + moveSet[0], tile_2m_POSITION[1]+ moveSet[1], tile_2m_POSITION[2]+moveSet[2]);  
    Rotate(modelView, tile_2m_ROTATE[0], tile_2m_ROTATE[1], tile_2m_ROTATE[2], tile_2m_ROTATE[3]);
    //-----------------------------------------------------------------------------|__MODEL_MATH        
    MultiplyMatrix(mvpMatrix, projection, modelView); 
    //------------------------------------------------------------------------------|__LIGHT_MATH
    LoadIdentity(lightMatrix);
    InvertMatrix(lightMatrix, modelView);
    //Translate(lightMatrix,   backWall_2x2_LIGHT_POSITION[0], backWall_2x2_LIGHT_POSITION[1], backWall_2x2_LIGHT_POSITION[2]);       
        // Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN+45);
        // Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);
    //======================================================================================================   
 
ShaderSelection();

if(SHADER_SELECTION == 0)
{             
             
             #include  "../../_SHADERS/BACKGROUND_SHADER_SELECTION.cpp"           
}    
    //======================================================================================================                                 
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D,  shadowMap_2D);    
    //---         
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,  tile_2m_NORMAL_TEX);
    //---
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,  tile_2m_TEXTURE1);    
    //-------------------------------------------------------------------------------|__DRAW     
    glDrawArrays(GL_TRIANGLES, 0, 30);   
