                      //---------------------------------                      
                      LoadIdentity(LightModelViewMatrix);
                      Translate(LightModelViewMatrix,  moveShadow_A[0],      moveShadow_A[2],      moveShadow_A[1]);        
                      Translate(LightModelViewMatrix,  0.0,  0.0 , -mainBodyPosition[1] * 0.9);
                      //Rotate(LightModelViewMatrix,   rotateShadow_01[0],      rotateShadow_01[1],    rotateShadow_01[2],  rotateShadow_01[3]); 
                      //--------------------------------------------------------------------------------------------------------------------------                                                       
    
   
    glBindBuffer(GL_ARRAY_BUFFER, hips_VBO);   
    
        //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL         
         
        //Translate(LightModelViewMatrix,  mainBodyPosition[1]*.75,   (mainBodyPosition[1] * 2.0),  0.0);//(mainBodyPosition) adjusts for shadow movement along XZ when model moves UP or DOWN
        
        Translate(LightModelViewMatrix,  hips_POSITION[0],    -hips_POSITION[1],    -hips_POSITION[2]);  
        Rotate(LightModelViewMatrix,     rotateShadow_A[0],    rotateShadow_A[1],    rotateShadow_A[2],                   rotateShadow_A[3]); 
        Rotate(LightModelViewMatrix,           0,                       1,                     0,        marcModel_ROTATE[3] * -1.0 + adjustModelShadow_A_ROTATION);      
        Rotate(LightModelViewMatrix,      hips_ROTATE[0],       hips_ROTATE[1],       hips_ROTATE[2],                     hips_ROTATE[3]);
        
        //Scale(LightModelViewMatrix,      scaleShadows + mainBodyPosition[1], scaleShadows + mainBodyPosition[1], scaleShadows + mainBodyPosition[1]);
        Scale(LightModelViewMatrix,           1.0,                                2.0,                                1.0);
         
        AssignMatrix(hipsMatrix, LightModelViewMatrix);         
        MultiplyMatrix(mvpMatrix , ProjectionShadow, LightModelViewMatrix); 
        //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                        glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
                        glEnableVertexAttribArray(0);	
                        glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
                        glEnableVertexAttribArray(1);               
                        //--------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS
                        glUniform4f(UNIFORM_darkness_shadow, darkness_shadow[0],  darkness_shadow[1], darkness_shadow[2], darkness_shadow[3]);         
                        //--------------
                        glUniformMatrix4fv(UNIFORM_MODELVIEW_shadow,     1, 0,  LightModelViewMatrix);
                        glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_shadow, 1, 0,  mvpMatrix);
                        glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_shadow,  1, 0,  lightMatrix);  
        //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
        glDrawArrays(GL_TRIANGLES, 0, 354);
//=====================================================================================================================
         
//torso_ROTATE[3]+=1.0;            
         
    glBindBuffer(GL_ARRAY_BUFFER, torso_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   torso_POSITION[0], torso_POSITION[1], torso_POSITION[2]);  
         Rotate(LightModelViewMatrix,  torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2], torso_ROTATE[3]);             //__torso_ROTATE[3]+spectrum[10]*500
         AssignMatrix(torsoMatrix, LightModelViewMatrix);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 912);   
//======================================================================================================================================================================
                                                                                                                                       
glBindBuffer(GL_ARRAY_BUFFER, head_VBO); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
LoadIdentity(LightModelViewMatrix);
AssignMatrix(LightModelViewMatrix, torsoMatrix); 
Translate(LightModelViewMatrix, head_neck_POSITION[0], head_neck_POSITION[1], head_neck_POSITION[2]);  
//-----------------
//Rotate(modelView, 15, 1.0, 0.0, 0.0);//ADJUST_FOR_NECK_ANGLE
//-----------------
Rotate(LightModelViewMatrix, head_ROTATE[0], head_ROTATE[1], head_ROTATE[2], head_ROTATE[3]);
MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
//---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
//LoadIdentity(lightMatrix);                                                                                                                                                
//InvertMatrix(lightMatrix, LightModelViewMatrix);                                                                                                                                     
//Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
//Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      
//======================================================================================================                                                                  
//--------------------------------------------------------------------------------------------------------------------------------------
#include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
//--------------------------------------------------------------------------------------------------------------------------------------                                                                                                                            
//---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
glDrawArrays(GL_TRIANGLES, 0, 1806);   

//======================================================================================================================================================================
//leftUpperArm_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, leftUpperArm_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, torsoMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftUpperArm_POSITION[0], leftUpperArm_POSITION[1], leftUpperArm_POSITION[2]);  
         Rotate(LightModelViewMatrix, leftUpperArm_ROTATE[0],leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2], leftUpperArm_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 486);   
//======================================================================================================================================================================

//leftForeArm_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, leftLowerArm_VBO);   
         
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftLowerArm_POSITION[0], leftLowerArm_POSITION[1], leftLowerArm_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftLowerArm_ROTATE[0], leftLowerArm_ROTATE[1], leftLowerArm_ROTATE[2], leftLowerArm_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 222);   
//======================================================================================================================================================================


//leftHand_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, leftHand_VBO);   
        
        //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftHand_POSITION[0], leftHand_POSITION[1], leftHand_POSITION[2]);  
         Rotate(LightModelViewMatrix, leftHand_ROTATE[0], leftHand_ROTATE[1], leftHand_ROTATE[2],leftHand_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //-------------------------------------------------------------------------------------------------------------------------------------- 
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 540);   
//======================================================================================================================================================================

//rightUpperArm_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, rightUpperArm_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, torsoMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightUpperArm_POSITION[0], rightUpperArm_POSITION[1], rightUpperArm_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightUpperArm_ROTATE[0], rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2], rightUpperArm_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 486);   
//======================================================================================================================================================================

//rightForeArm_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, rightLowerArm_VBO);   
         
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightLowerArm_POSITION[0], rightLowerArm_POSITION[1], rightLowerArm_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightLowerArm_ROTATE[0], rightLowerArm_ROTATE[1], rightLowerArm_ROTATE[2], rightLowerArm_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------  
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 222);   
//======================================================================================================================================================================


//rightHand_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, rightHand_VBO);   
        
        //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightHand_POSITION[0], rightHand_POSITION[1], rightHand_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightHand_ROTATE[0], rightHand_ROTATE[1], rightHand_ROTATE[2],  rightHand_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------  
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 540);   
//======================================================================================================================================================================

//leftUpperLeg_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, leftUpperLeg_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, hipsMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftUpperLeg_POSITION[0], leftUpperLeg_POSITION[1], leftUpperLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftUpperLeg_ROTATE[0], leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2], leftUpperLeg_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 288);   
//======================================================================================================================================================================

//leftLowerLeg_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, leftLowerLeg_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftLowerLeg_POSITION[0], leftLowerLeg_POSITION[1], leftLowerLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2], leftLowerLeg_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //-------------------------------------------------------------------------------------------------------------------------------------- 
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 258);   
//======================================================================================================================================================================

//leftFoot_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, leftFoot_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftFoot_POSITION[0], leftFoot_POSITION[1], leftFoot_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2],leftFoot_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 300);   
//======================================================================================================================================================================

//rightUpperLeg_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, rightUpperLeg_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, hipsMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightUpperLeg_POSITION[0], rightUpperLeg_POSITION[1], rightUpperLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightUpperLeg_ROTATE[0], rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2], rightUpperLeg_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------   
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 288);   
//======================================================================================================================================================================

//rightLowerLeg_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, rightLowerLeg_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightLowerLeg_POSITION[0], rightLowerLeg_POSITION[1], rightLowerLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightLowerLeg_ROTATE[0], rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2], rightLowerLeg_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------  
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 258);   
//======================================================================================================================================================================

//rightFoot_ROTATE[3]+=1.0;      
    
    glBindBuffer(GL_ARRAY_BUFFER, rightFoot_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightFoot_POSITION[0], rightFoot_POSITION[1], rightFoot_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightFoot_ROTATE[0], rightFoot_ROTATE[1], rightFoot_ROTATE[2], rightFoot_ROTATE[3]);
         MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------  
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 300);  
