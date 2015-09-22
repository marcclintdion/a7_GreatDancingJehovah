          //-----------------------------------------------------------------------------                                             
                                                                                                   
          glBindBufferARB(GL_ARRAY_BUFFER, chestArmor_VBO);                                                                          
          //-----------------------------------------------------------------------------|__TRANSFORMATIONS                           
         // LoadIdentity(ModelView);                                                                                                    
          Translate(modelView,   chestArmor_POSITION[0], chestArmor_POSITION[1], chestArmor_POSITION[2]);                          
          //Rotate(ModelView, 1.0, 0.0, 0.0, chestArmor_ROTATE[3]);                                                                    
          //Scale(modelView,chestArmor_SCALE,chestArmor_SCALE, chestArmor_SCALE);                                                  
          //-----------------------------------------------------------------------------|__MATRIX_MATH                               
          //MultiplyMatrix(ModelViewProjection, Projection, ModelView);                                                                 
          //InvertMatrix(ModelViewProjectionInverse, ModelViewProjection);                                                              
          //AssignMatrix(textureMatrix, bias);                                                                                        
          //------------------------------------------------------------------------------|__LIGHT                                    
          LoadIdentity(lightMatrix);
          InvertMatrix(lightMatrix, modelView);
          Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
          Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                   
                                                                                             
          //------------------------------------------------------------------------------|__UNIFORMS                                 

ShaderSelection();
 
       
if(SHADER_SELECTION == 0)
          {
          glUseProgram(chestArmor_SHADER);  
          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
          //--------------------------                                                                                                
          //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
          //glEnableVertexAttribArray(0);	                                                                                          
          //--------------------------                                                                                                
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);            
          
          glUniform4f(UNIFORM_LIGHT_POSITION_01_chestArmor,                   chestArmor_LIGHT_POSITION_01[0],                       
                                                                              chestArmor_LIGHT_POSITION_01[1],                       
                                                                              chestArmor_LIGHT_POSITION_01[2],                       
                                                                              chestArmor_LIGHT_POSITION_01[3]);                      

          glUniformMatrix4fv(UNIFORM_MODELVIEW_chestArmor, 1, 0,              modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_chestArmor, 1, 0,          mvpMatrix);                                   
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_chestArmor, 1, 0,  mvpMatrixInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_chestArmor,  1, 0,          lightMatrix);                                           
          //glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_chestArmor,  1, 0,      textureMatrix);   
          glUniform1iARB(UNIFORM_TEXTURE_DOT3_chestArmor, 1);
          glUniform1iARB(UNIFORM_TEXTURE_chestArmor, 0);                                     
          }
          //------------------------------------------------------------------------------|__TEXTURES                                 
          glActiveTextureARB(GL_TEXTURE1_ARB);                                                                                        
          glBindTexture(GL_TEXTURE_2D,  chestArmor_NORMAL_TEX);                                                                      
          //---                                                                                                                       
          glActiveTextureARB(GL_TEXTURE0_ARB);                                                                                        
          glBindTexture(GL_TEXTURE_2D, chestArmor_TEXTURE1);                                                                         
          //-------------------------------------------------------------------------------|__DRAW                                    
          glDrawArrays(GL_TRIANGLES, 0, 1008);                                                           

