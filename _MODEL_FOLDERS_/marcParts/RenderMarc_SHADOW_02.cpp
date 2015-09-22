                      LoadIdentity(LightModelViewMatrix);
                      Translate(LightModelViewMatrix, moveShadow_A[0] + moveShadow_B[0],    moveShadow_A[2] + moveShadow_B[2],    moveShadow_A[1] +   moveShadow_B[1]);        
                      Translate(LightModelViewMatrix,  0.0,         0.0,     -mainBodyPosition[1]*.9);
                      Rotate(LightModelViewMatrix,     rotateShadow_02[0],    rotateShadow_02[1],    rotateShadow_02[2],  rotateShadow_02[3]);                                                        
    
   
    glBindBufferARB(GL_ARRAY_BUFFER, hips_VBO);   
    
         
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL         
         
        // Translate(LightModelViewMatrix,  mainBodyPosition[1]*.2,   mainBodyPosition[1] * 3.5,            0.0);                                          //___(mainBodyPosition) adjusts for shadow movement along XZ when model moves UP or DOWN
         
         Translate(LightModelViewMatrix,  hips_POSITION[0],            -hips_POSITION[1],           -hips_POSITION[2]);  
         
         Rotate(LightModelViewMatrix,           0,                1,                0,           marcDirectionFacingRotation * -1.0 + adjustModelShadow_02_ROTATION);        
         Rotate(LightModelViewMatrix,     hips_ROTATE[0],   hips_ROTATE[1],   hips_ROTATE[2],    hips_ROTATE[3]);
         
         //Scale(LightModelViewMatrix,      scaleShadows + mainBodyPosition[1], scaleShadows + mainBodyPosition[1], scaleShadows + mainBodyPosition[1]);
         Scale(LightModelViewMatrix,           1.0,                                2.5,                                1.0);
         
         AssignMatrix(hipsMatrix, LightModelViewMatrix);         
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 354);   
//=====================================================================================================================
         
//torso_ROTATE[3]+=1.0;            
         
    glBindBufferARB(GL_ARRAY_BUFFER, torso_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   torso_POSITION[0], torso_POSITION[1], torso_POSITION[2]);  
         Rotate(LightModelViewMatrix,  torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2], torso_ROTATE[3]);             //__torso_ROTATE[3]+spectrum[10]*500
         AssignMatrix(torsoMatrix, LightModelViewMatrix);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //-------------------------------------------------------------------------------------------------------------------------------------- 
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 912);   
//=====================================================================================================================
    
//head_neck_ROTATE[3]+=1.0; 
         
    glBindBufferARB(GL_ARRAY_BUFFER, head_neck_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   head_neck_POSITION[0], head_neck_POSITION[1], head_neck_POSITION[2]);  
         Rotate(LightModelViewMatrix,  head_neck_ROTATE[0], head_neck_ROTATE[1], head_neck_ROTATE[2], head_neck_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 390);   
//=====================================================================================================================
    glBindBufferARB(GL_ARRAY_BUFFER, face_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 1416);   
//=====================================================================================================================



//leftUpperArm_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, leftUpperArm_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, torsoMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftUpperArm_POSITION[0], leftUpperArm_POSITION[1], leftUpperArm_POSITION[2]);  
         Rotate(LightModelViewMatrix, leftUpperArm_ROTATE[0],leftUpperArm_ROTATE[1], leftUpperArm_ROTATE[2], leftUpperArm_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 486);   
//=====================================================================================================================

//leftForeArm_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, leftForeArm_VBO);   
         
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftForeArm_POSITION[0], leftForeArm_POSITION[1], leftForeArm_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftForeArm_ROTATE[0], leftForeArm_ROTATE[1], leftForeArm_ROTATE[2], leftForeArm_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 222);   
//=====================================================================================================================


//leftHand_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, leftHand_VBO);   
        
        //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftHand_POSITION[0], leftHand_POSITION[1], leftHand_POSITION[2]);  
         Rotate(LightModelViewMatrix, leftHand_ROTATE[0], leftHand_ROTATE[1], leftHand_ROTATE[2],leftHand_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //-------------------------------------------------------------------------------------------------------------------------------------- 
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 540);   
//=====================================================================================================================

//rightUpperArm_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, rightUpperArm_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, torsoMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightUpperArm_POSITION[0], rightUpperArm_POSITION[1], rightUpperArm_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightUpperArm_ROTATE[0], rightUpperArm_ROTATE[1], rightUpperArm_ROTATE[2], rightUpperArm_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
         glDrawArrays(GL_TRIANGLES, 0, 486);   
//=====================================================================================================================

//rightForeArm_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, rightForeArm_VBO);   
         
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightForeArm_POSITION[0], rightForeArm_POSITION[1], rightForeArm_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightForeArm_ROTATE[0], rightForeArm_ROTATE[1], rightForeArm_ROTATE[2], rightForeArm_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 222);   
//=====================================================================================================================


//rightHand_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, rightHand_VBO);   
        
        //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightHand_POSITION[0], rightHand_POSITION[1], rightHand_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightHand_ROTATE[0], rightHand_ROTATE[1], rightHand_ROTATE[2],  rightHand_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------  
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 540);   
//=====================================================================================================================

//leftUpperLeg_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, leftUpperLeg_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, hipsMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftUpperLeg_POSITION[0], leftUpperLeg_POSITION[1], leftUpperLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftUpperLeg_ROTATE[0], leftUpperLeg_ROTATE[1], leftUpperLeg_ROTATE[2], leftUpperLeg_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------  
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 288);   
//=====================================================================================================================

//leftLowerLeg_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, leftLowerLeg_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftLowerLeg_POSITION[0], leftLowerLeg_POSITION[1], leftLowerLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2], leftLowerLeg_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //-------------------------------------------------------------------------------------------------------------------------------------- 
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 258);   
//=====================================================================================================================

//leftFoot_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, leftFoot_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   leftFoot_POSITION[0], leftFoot_POSITION[1], leftFoot_POSITION[2]);  
         Rotate(LightModelViewMatrix,  leftLowerLeg_ROTATE[0], leftLowerLeg_ROTATE[1], leftLowerLeg_ROTATE[2],leftFoot_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
        //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------   
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 300);   
//=====================================================================================================================

//rightUpperLeg_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, rightUpperLeg_VBO);   
         LoadIdentity(LightModelViewMatrix);
         AssignMatrix(LightModelViewMatrix, hipsMatrix);
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightUpperLeg_POSITION[0], rightUpperLeg_POSITION[1], rightUpperLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightUpperLeg_ROTATE[0], rightUpperLeg_ROTATE[1], rightUpperLeg_ROTATE[2], rightUpperLeg_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
         //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------    
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 288);   
//=====================================================================================================================

//rightLowerLeg_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, rightLowerLeg_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightLowerLeg_POSITION[0], rightLowerLeg_POSITION[1], rightLowerLeg_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightLowerLeg_ROTATE[0], rightLowerLeg_ROTATE[1], rightLowerLeg_ROTATE[2], rightLowerLeg_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
          //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------   
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 258);   
//=====================================================================================================================

//rightFoot_ROTATE[3]+=1.0;      
    
    glBindBufferARB(GL_ARRAY_BUFFER, rightFoot_VBO);   
         //--------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
         Translate(LightModelViewMatrix,   rightFoot_POSITION[0], rightFoot_POSITION[1], rightFoot_POSITION[2]);  
         Rotate(LightModelViewMatrix, rightFoot_ROTATE[0], rightFoot_ROTATE[1], rightFoot_ROTATE[2], rightFoot_ROTATE[3]);
         MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
        //--------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
         //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
         //--------------------------------------------------------------------------------------------------------------------------------------|__DRAW     
         glDrawArrays(GL_TRIANGLES, 0, 300);  
