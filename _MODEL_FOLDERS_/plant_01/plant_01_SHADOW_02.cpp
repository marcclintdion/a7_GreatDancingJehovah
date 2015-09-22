                    
                    
                      plant_01_POSITION[0]   =   movePiece[0];                                                                                                 
                      plant_01_POSITION[1]   =   movePiece[1];                                                                                                 
                      plant_01_POSITION[2]   =   movePiece[2];                         
                      //-----------------------------
                      glBindBufferARB(GL_ARRAY_BUFFER, plant_01_VBO);  
                      //--------------------------------------------------------------------------------------------------------------------------------------|__TRANSFORMATIONS  
                      LoadIdentity(LightModelViewMatrix);
                      
                      Translate(LightModelViewMatrix,    moveShadow_01[0] + moveShadow_02[0]-goldenSunset_LIGHT_POSITION_01[0]*.05,  moveShadow_01[2] +  moveShadow_02[2],  moveShadow_01[1] +  moveShadow_02[1]-goldenSunset_LIGHT_POSITION_01[2]*.05); 
                      
                      Translate(LightModelViewMatrix,     (moveSet[0]+moveShadow_plant_02[0]-(moveSet[1]*0.320001))*.92,  -(moveSet[2] +moveShadow_plant_02[2])*0.92*scaleShadowMove,  -(moveSet[1] +moveShadow_plant_02[1])*0.92*scaleShadowMove);              
                     
                      Translate(LightModelViewMatrix,     plant_01_POSITION[0],                      plant_01_POSITION[2],                      plant_01_POSITION[1]); 
                      Rotate(LightModelViewMatrix,        plant_01_ROTATE[0],                        plant_01_ROTATE[1],                        plant_01_ROTATE[2],                plant_01_ROTATE[3]);   
                      Scale(LightModelViewMatrix, .8, .8, .8);
                      //--------------------------------------------------------------------------------------------------------------------------------------|__MATRIX_MATH
                      MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
                      //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
                      glDrawArrays(GL_TRIANGLES, 0, 804);  	 
