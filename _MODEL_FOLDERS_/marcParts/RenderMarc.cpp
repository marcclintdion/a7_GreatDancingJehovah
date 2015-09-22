

//marcModel_ROTATE[3]+= .4;
//############################################################################################################################################################   
//############################################################################################################################################################ 
//############################################################################################################################################################ 
//############################################################################################################################################################ 

  
glBindBuffer(GL_ARRAY_BUFFER, hips_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
Translate(modelView, marcModelPosition[0], marcModelPosition[1], marcModelPosition[2]);    
Rotate(modelView, marcModel_ROTATE[0], marcModel_ROTATE[1], marcModel_ROTATE[2], marcModel_ROTATE[3] * -1.0 );//--MODEL
Rotate(modelView, hips_ROTATE[0], hips_ROTATE[1], hips_ROTATE[2], hips_ROTATE[3]);//--MODEL
//Translate(modelView, hips_POSITION[0], hips_POSITION[1], hips_POSITION[2]);  
Rotate(modelView, hips_ROTATE[0], hips_ROTATE[1], hips_ROTATE[2], hips_ROTATE[3]);//--MODEL
AssignMatrix(hipsMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);  
       
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection();  
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER);
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1); 
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, hips_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, hips_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 354);       
///############################################################################################################################################################   

glBindBuffer(GL_ARRAY_BUFFER, torso_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, hipsMatrix); 
Translate(modelView, torso_POSITION[0], torso_POSITION[1], torso_POSITION[2]);  
Rotate(modelView, torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2], torso_ROTATE[3]);
AssignMatrix(torsoMatrix, modelView);    
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER); 

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1);  
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, torso_NORMALMAP);     
  
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, torso_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 912);           

#include "../chestArmor/chestArmor_Render.cpp"       

///############################################################################################################################################################   
///############################################################################################################################################################      
                                                                                                                                            
glBindBuffer(GL_ARRAY_BUFFER, head_VBO); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, torsoMatrix); 
Translate(modelView, head_neck_POSITION[0], head_neck_POSITION[1], head_neck_POSITION[2]);  
//-----------------
//Rotate(modelView, 15, 1.0, 0.0, 0.0);//ADJUST_FOR_NECK_ANGLE
//-----------------
Rotate(modelView, head_ROTATE[0], head_ROTATE[1], head_ROTATE[2], head_ROTATE[3]);
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
LoadIdentity(lightMatrix);                                                                                                                                                
InvertMatrix(lightMatrix, modelView);                                                                                                                                     
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      
//======================================================================================================                                                                  

ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(head_SHADER);  

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
glEnableVertexAttribArray(0);	                                                                                                                                          
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
glEnableVertexAttribArray(1);                                                                                                                                             
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          

glUniform4f(UNIFORM_LIGHT_POSITION_01_head, head_LIGHT_POSITION_01[0], head_LIGHT_POSITION_01[1], head_LIGHT_POSITION_01[2], head_LIGHT_POSITION_01[3]);        
glUniform1f(UNIFORM_SHININESS_head, head_SHININESS);                                                                                                                  
glUniform1f(UNIFORM_ATTENUATION_head, head_ATTENUATION);                                                                                                                  
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_head,   1,0,  mvpMatrix);                                                                                                      
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_head,    1,0,  lightMatrix);                                                                                                    
glUniform1i (UNIFORM_TEXTURE_DOT3_head, 1);
glUniform1i (UNIFORM_TEXTURE_head, 0 ); 
}
//======================================================================================================                                                                  
glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, head_NORMALMAP);                                                                                                                          
                                                                                                                             
//---                                                                                                                                                                     
glActiveTexture (GL_TEXTURE0);                                                                                                                                            
glBindTexture(GL_TEXTURE_2D, head_TEXTUREMAP);                                                                                                                            
                                                                                                                                
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
glDrawArrays(GL_TRIANGLES, 0, 1806);       
///############################################################################################################################################################   
///############################################################################################################################################################      
///############################################################################################################################################################   
///############################################################################################################################################################   

glBindBuffer(GL_ARRAY_BUFFER, leftUpperArm_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, torsoMatrix);    
Translate(modelView, leftUpperArm_POSITION[0], leftUpperArm_POSITION[1], leftUpperArm_POSITION[2]);  
Rotate(modelView, leftUpperArm_ROTATE[0], leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2], leftUpperArm_ROTATE[3]);
AssignMatrix(leftUpperArmMatrix, modelView);
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 

ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER);                          
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
                         
glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1);
glUniform1i (UNIFORM_TEXTURE_marc, 0 );
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftUpperArm_NORMALMAP);     
    
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftUpperArm_TEXTUREMAP);    
    
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 486);   
///############################################################################################################################################################       

glBindBuffer(GL_ARRAY_BUFFER, leftLowerArm_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, leftUpperArmMatrix);
Translate(modelView, leftLowerArm_POSITION[0], leftLowerArm_POSITION[1], leftLowerArm_POSITION[2]);  
Rotate(modelView, leftLowerArm_ROTATE[0], leftLowerArm_ROTATE[1], leftLowerArm_ROTATE[2], leftLowerArm_ROTATE[3]);
AssignMatrix(leftLowerArmMatrix, modelView);
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER); 

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1);
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftLowerArm_NORMALMAP);     
    
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftLowerArm_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 222);   
///############################################################################################################################################################  
///############################################################################################################################################################  

glBindBuffer(GL_ARRAY_BUFFER, leftHand_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, leftLowerArmMatrix);
Translate(modelView, leftHand_POSITION[0], leftHand_POSITION[1], leftHand_POSITION[2]);  
Rotate(modelView, leftHand_ROTATE[0], leftHand_ROTATE[1], leftHand_ROTATE[2], leftHand_ROTATE[3]);
AssignMatrix(leftHandMatrix, modelView);
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,   look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection();  
       
if(SHADER_SELECTION == 0)
{
glUseProgram(head_SHADER); 

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_LIGHT_POSITION_01_head, head_LIGHT_POSITION_01[0], head_LIGHT_POSITION_01[1], head_LIGHT_POSITION_01[2], head_LIGHT_POSITION_01[3]);        
glUniform1f(UNIFORM_SHININESS_head, head_SHININESS);                                                                                                                  
glUniform1f(UNIFORM_ATTENUATION_head, head_ATTENUATION);                                                                                                                  
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_head,   1,0,  mvpMatrix);                                                                                                      
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_head,    1,0,  lightMatrix);       
glUniform1i (UNIFORM_TEXTURE_DOT3_head, 1); 
glUniform1i (UNIFORM_TEXTURE_head, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftHand_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftHand_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 540);   
///############################################################################################################################################################  
///############################################################################################################################################################  
///############################################################################################################################################################
///############################################################################################################################################################      

glBindBuffer(GL_ARRAY_BUFFER, rightUpperArm_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, torsoMatrix);    
Translate(modelView, rightUpperArm_POSITION[0], rightUpperArm_POSITION[1], rightUpperArm_POSITION[2]);  
Rotate(modelView, rightUpperArm_ROTATE[0], rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2], rightUpperArm_ROTATE[3]);
AssignMatrix(rightUpperArmMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER); 

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1); 
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, rightUpperArm_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, rightUpperArm_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 486);   
//############################################################################################################################################################  

glBindBuffer(GL_ARRAY_BUFFER, rightLowerArm_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, rightUpperArmMatrix);  
Translate(modelView, rightLowerArm_POSITION[0], rightLowerArm_POSITION[1], rightLowerArm_POSITION[2]);  
Rotate(modelView, rightLowerArm_ROTATE[0], rightLowerArm_ROTATE[1], rightLowerArm_ROTATE[2], rightLowerArm_ROTATE[3]);
AssignMatrix(rightLowerArmMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER); 
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1); 
glUniform1i (UNIFORM_TEXTURE_marc, 0 );  
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, rightLowerArm_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, rightLowerArm_TEXTUREMAP);    
  
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 222);   
//############################################################################################################################################################ 
//############################################################################################################################################################ 

glBindBuffer(GL_ARRAY_BUFFER, rightHand_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, rightLowerArmMatrix);
Translate(modelView, rightHand_POSITION[0], rightHand_POSITION[1], rightHand_POSITION[2]);  
Rotate(modelView, rightHand_ROTATE[0], rightHand_ROTATE[1], rightHand_ROTATE[2], rightHand_ROTATE[3]);
AssignMatrix(rightHandMatrix, modelView);
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(head_SHADER); 

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_LIGHT_POSITION_01_head, head_LIGHT_POSITION_01[0], head_LIGHT_POSITION_01[1], head_LIGHT_POSITION_01[2], head_LIGHT_POSITION_01[3]);        
glUniform1f(UNIFORM_SHININESS_head, head_SHININESS);                                                                                                                  
glUniform1f(UNIFORM_ATTENUATION_head, head_ATTENUATION);                                                                                                                  
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_head,   1,0,  mvpMatrix);                                                                                                      
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_head,    1,0,  lightMatrix);         
glUniform1i (UNIFORM_TEXTURE_DOT3_head, 1); 
glUniform1i (UNIFORM_TEXTURE_head, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, rightHand_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, rightHand_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 540);   

//############################################################################################################################################################       
//############################################################################################################################################################  
//############################################################################################################################################################ 
//############################################################################################################################################################ 

glBindBuffer(GL_ARRAY_BUFFER, leftUpperLeg_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, hipsMatrix);    
Translate(modelView, leftUpperLeg_POSITION[0], leftUpperLeg_POSITION[1], leftUpperLeg_POSITION[2]);  
Rotate(modelView, leftUpperLeg_ROTATE[0], leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2], leftUpperLeg_ROTATE[3]);
AssignMatrix(leftUpperLegMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection();
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER); 

glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1);
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftUpperLeg_NORMALMAP);     
    
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftUpperLeg_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 288);       
//############################################################################################################################################################     


glBindBuffer(GL_ARRAY_BUFFER, leftLowerLeg_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, leftUpperLegMatrix); 
Translate(modelView, leftLowerLeg_POSITION[0], leftLowerLeg_POSITION[1], leftLowerLeg_POSITION[2]);  
Rotate(modelView, leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2], leftLowerLeg_ROTATE[3]);
AssignMatrix(leftLowerLegMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER); 
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       

glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1); 
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftLowerLeg_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftLowerLeg_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 258);         
//############################################################################################################################################################ 
//############################################################################################################################################################ 

glBindBuffer(GL_ARRAY_BUFFER, leftFoot_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, leftLowerLegMatrix); 
Translate(modelView, leftFoot_POSITION[0], leftFoot_POSITION[1], leftFoot_POSITION[2]);  
Rotate(modelView, leftFoot_ROTATE[0], leftFoot_ROTATE[1], leftFoot_ROTATE[2], leftFoot_ROTATE[3]);
AssignMatrix(leftFootMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);        
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(head_SHADER); 
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
glUniform4f(UNIFORM_LIGHT_POSITION_01_head, shoes_LIGHT_POSITION_01[0], shoes_LIGHT_POSITION_01[1], shoes_LIGHT_POSITION_01[2], shoes_LIGHT_POSITION_01[3]);        
glUniform1f(UNIFORM_SHININESS_head, shoes_SHININESS);                                                                                                                  
glUniform1f(UNIFORM_ATTENUATION_head, shoes_ATTENUATION);                                                                                                                  
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_head,   1,0,  mvpMatrix);                                                                                                      
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_head,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_head, 1); 
glUniform1i (UNIFORM_TEXTURE_head, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftFoot_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftFoot_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 300);         

//############################################################################################################################################################     
//############################################################################################################################################################  
//############################################################################################################################################################ 
//############################################################################################################################################################ 

 
glBindBuffer(GL_ARRAY_BUFFER, rightUpperLeg_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, hipsMatrix);    
Translate(modelView, rightUpperLeg_POSITION[0], rightUpperLeg_POSITION[1], rightUpperLeg_POSITION[2]);  
Rotate(modelView, rightUpperLeg_ROTATE[0], rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2], rightUpperLeg_ROTATE[3]);
AssignMatrix(rightUpperLegMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection(); 
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER);
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1);
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, rightUpperLeg_NORMALMAP);     
    
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, rightUpperLeg_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 288);       
//############################################################################################################################################################     
 
glBindBuffer(GL_ARRAY_BUFFER, rightLowerLeg_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, rightUpperLegMatrix); 
Translate(modelView, rightLowerLeg_POSITION[0], rightLowerLeg_POSITION[1], rightLowerLeg_POSITION[2]);  
Rotate(modelView, rightLowerLeg_ROTATE[0], rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2], rightLowerLeg_ROTATE[3]);
AssignMatrix(rightLowerLegMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
ShaderSelection();  
       
if(SHADER_SELECTION == 0)
{
glUseProgram(marc_SHADER);
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
glUniform4f(UNIFORM_marc_LIGHT_POSITION_01, marc_LIGHT_POSITION_01[0], marc_LIGHT_POSITION_01[1], marc_LIGHT_POSITION_01[2], marc_LIGHT_POSITION_01[3]);    
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX,    1,0,  lightMatrix);        
glUniform1i (UNIFORM_TEXTURE_DOT3_marc, 1);
glUniform1i (UNIFORM_TEXTURE_marc, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, rightLowerLeg_NORMALMAP);     
    
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, rightLowerLeg_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 258);         
//############################################################################################################################################################ 
//############################################################################################################################################################ 

glBindBuffer(GL_ARRAY_BUFFER, rightFoot_VBO);
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(modelView);
AssignMatrix(modelView, rightLowerLegMatrix); 
Translate(modelView, rightFoot_POSITION[0], rightFoot_POSITION[1], rightFoot_POSITION[2]);  
Rotate(modelView, rightFoot_ROTATE[0], rightFoot_ROTATE[1], rightFoot_ROTATE[2], rightFoot_ROTATE[3]);
AssignMatrix(rightFootMatrix, modelView); 
MultiplyMatrix(mvpMatrix, projection, modelView); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
LoadIdentity(lightMatrix);
InvertMatrix(lightMatrix, modelView);
Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 

ShaderSelection();
       
if(SHADER_SELECTION == 0)
{
glUseProgram(head_SHADER);                          
glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);	
glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
glUniform4f(UNIFORM_LIGHT_POSITION_01_head, shoes_LIGHT_POSITION_01[0], shoes_LIGHT_POSITION_01[1], shoes_LIGHT_POSITION_01[2], shoes_LIGHT_POSITION_01[3]);        
glUniform1f(UNIFORM_SHININESS_head, shoes_SHININESS);                                                                                                                  
glUniform1f(UNIFORM_ATTENUATION_head, shoes_ATTENUATION);                                                                                                                  
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_head,   1,0,  mvpMatrix);                                                                                                      
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_head,    1,0,  lightMatrix);       
glUniform1i (UNIFORM_TEXTURE_DOT3_head, 1); 
glUniform1i (UNIFORM_TEXTURE_head, 0 ); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
glActiveTexture ( GL_TEXTURE1 );
glBindTexture(GL_TEXTURE_2D, leftFoot_NORMALMAP);     
   
//---
glActiveTexture (GL_TEXTURE0); 
glBindTexture(GL_TEXTURE_2D, leftFoot_TEXTUREMAP);    
   
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
glDrawArrays(GL_TRIANGLES, 0, 300);         

//############################################################################################################################################################      
//############################################################################################################################################################      
//############################################################################################################################################################    
//############################################################################################################################################################     

 
 
 
 
 
