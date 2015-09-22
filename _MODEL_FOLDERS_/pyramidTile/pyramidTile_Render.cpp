          
          
          
          glBindBuffer(GL_ARRAY_BUFFER, pyramidTile_VBO);                                                                          
          //-----------------------------------------------------------------------------|__TRANSFORMATIONS                           
          LoadIdentity(modelView);                                                                                                    
          Translate(modelView,   pyramidTile_POSITION[0] + moveSet[0], pyramidTile_POSITION[1]+ moveSet[1], pyramidTile_POSITION[2]+moveSet[2]);                          
          Rotate(modelView, pyramidTile_ROTATE[0], pyramidTile_ROTATE[1]+1.0, pyramidTile_ROTATE[2], pyramidTile_ROTATE[3]);                                                                    
          //Scale(modelView,pyramidTile_SCALE,pyramidTile_SCALE, pyramidTile_SCALE);                                                  
          //-----------------------------------------------------------------------------|__MATRIX_MATH                               
          MultiplyMatrix(mvpMatrix, projection, modelView);                                                                 
          //InvertMatrix(mvpMatrix, ModelViewProjection);                                                              
          //AssignMatrix(TextureMatrix, bias);                                                                                        
          //------------------------------------------------------------------------------|__LIGHT                                    
          LoadIdentity(lightMatrix);                                                                                                  
          InvertMatrix(lightMatrix, modelView);                                                                                       
          //Translate(LightMatrix, pyramidTile_LIGHT_POSITION[0] , pyramidTile_LIGHT_POSITION[1] ,pyramidTile_LIGHT_POSITION[2]);                                                                                    
         Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN+45);
         Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);          
          //------------------------------------------------------------------------------|__ATTRIBUTES                               
          
          
          //===============================================================================================================================          
 
ShaderSelection();

if(SHADER_SELECTION == 0)
{       
        if(BASE_LIGHTING == true)
        {
             #include  "../../_SHADERS/BASIC/baseLighting_RENDER.cpp"  
        }   
        
         
        if(GOLDEN_SUNSET_LIGHTING == true)
        {
             #include  "../../_SHADERS/BACKGROUND/goldenSunset_RENDER.cpp"    
        }
}                 
          //===============================================================================================================================
          
          
          glActiveTexture(GL_TEXTURE1);                                                                                        
          glBindTexture(GL_TEXTURE_2D,  pyramidTile_NORMAL_TEX);          
          glActiveTexture(GL_TEXTURE0);                                                                                        
          glBindTexture(GL_TEXTURE_2D,   pyramidTile_TEXTURE1);                                                                         
          //-------------------------------------------------------------------------------|__DRAW                                    
          glDrawArrays(GL_TRIANGLES, 0, 30);                                                           

