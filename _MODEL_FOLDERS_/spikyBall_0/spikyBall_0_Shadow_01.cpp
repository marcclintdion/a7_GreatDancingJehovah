                 
                      //-----------------------------                      
                      glBindBuffer(GL_ARRAY_BUFFER, spikyBall_0_VBO);   
                      //-------------------------------------------------------------------------------------------------------------------------------------------|__TRANSFORMATIONS         
                      LoadIdentity(LightModelViewMatrix);
                      InvertMatrix(LightModelViewMatrix, ProjectionShadow);
                      //-------------------------------------------------------------------------------------------------------------------------------------------
                      Translate(LightModelViewMatrix,     moveSet[0] * 0.113+ moveShadow_A_spikyBall_0[0]-spikyBall_0_POSITION[1]*.08,            0.0,   0.0); 
                      Translate(LightModelViewMatrix,     spikyBall_0_POSITION[0] * 0.112,        0.0,   0.0 );                      
                      //------------------------------ 
                      Rotate(LightModelViewMatrix,                   0.0,  0.0,   1.0,  -20); 
                      //------------------------------ 
                      Translate(LightModelViewMatrix,     0.0,   -moveSet[2] * 0.094 +  moveShadow_A_spikyBall_0[2] + spikyBall_0_POSITION[1] * .08,       0.0); 
                      Translate(LightModelViewMatrix,     0.0,   -spikyBall_0_POSITION[2] * 0.09,  0.0 );     
                      //------------------------------ 
                      Rotate(LightModelViewMatrix,        spikyBall_0_ROTATE[0], spikyBall_0_ROTATE[1], spikyBall_0_ROTATE[2], spikyBall_0_ROTATE[3]);                                        
                      //------------------------------ 
                      Scale(LightModelViewMatrix, spikyBall_0_SCALE,   spikyBall_0_SCALE,  spikyBall_0_SCALE);
                      Scale(LightModelViewMatrix, 1+spikyBall_0_POSITION[1] * .5,   1 + spikyBall_0_POSITION[1] * .5,  1 + spikyBall_0_POSITION[1] * .5);
                      //--------------------------------------------------------------------------------------------------------------------------------------|__MATRIX_MATH
                      MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
                      
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      
                      glDrawArrays(GL_TRIANGLES, 0, 540);  	 
