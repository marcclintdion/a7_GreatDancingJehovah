                 
                      //-----------------------------                      
                      glBindBufferARB(GL_ARRAY_BUFFER, spikyBall_5_VBO);   
                      //--------------------------------------------------------------------------------------------------------------------------------------|__TRANSFORMATIONS         
                      LoadIdentity(LightModelViewMatrix);
                      InvertMatrix(LightModelViewMatrix, ProjectionShadow);
                      
                    //  Translate(LightModelViewMatrix,     moveSet[0]*.88-(moveSet[1]*0.320001),               -(moveSet[2]-moveSet[1])*.88/2.0,            (moveSet[2]-moveSet[1])*.88/2.0);                
                     // Translate(LightModelViewMatrix,     moveShadow_01[0],            moveShadow_01[2],            moveShadow_01[1]); 
                      
                                
                      
                      Translate(LightModelViewMatrix,     moveSet[0] * 0.113+ moveShadow_B_spikyBall_5[0]-spikyBall_5_POSITION[1]*.01,            0.0,   0.0); 
                      Translate(LightModelViewMatrix,     spikyBall_5_POSITION[0]*0.112,        0.0,   0.0 );                      
                       
                      Rotate(LightModelViewMatrix,                   0.0,  0.0,   1.0,  -20); 
                      
                      Translate(LightModelViewMatrix,     0.0,   -moveSet[2] * 0.094 +  moveShadow_B_spikyBall_5[2]+spikyBall_5_POSITION[1]*.08,       0.0); 
                      Translate(LightModelViewMatrix,     0.0,  -spikyBall_5_POSITION[2] * 0.09,  0.0 );     
                     
                     // Rotate(LightModelViewMatrix,     rotateShadow_01[0],    rotateShadow_01[1],    rotateShadow_01[2],  rotateShadow_01[3]); 
                     
                      Rotate(LightModelViewMatrix,        spikyBall_5_ROTATE[0],                        spikyBall_5_ROTATE[1],                        spikyBall_5_ROTATE[2],                spikyBall_5_ROTATE[3]);                                        
                      Scale(LightModelViewMatrix, spikyBall_5_SCALE,   spikyBall_5_SCALE,  spikyBall_5_SCALE);
                      Scale(LightModelViewMatrix, 1+spikyBall_5_POSITION[1]*.5,   1+spikyBall_5_POSITION[1]*.5,  1+spikyBall_5_POSITION[1]*.5);
                      //--------------------------------------------------------------------------------------------------------------------------------------|__MATRIX_MATH
                      MultiplyMatrix(ModelViewProjection, ProjectionShadow, LightModelViewMatrix); 
                      //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
                      glDrawArrays(GL_TRIANGLES, 0, 540);  	 
