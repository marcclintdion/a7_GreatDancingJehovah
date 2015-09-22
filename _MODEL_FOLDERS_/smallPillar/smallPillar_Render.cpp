       
          
          
          glBindBufferARB(GL_ARRAY_BUFFER, smallPillar_VBO);                                                                          
          //-----------------------------------------------------------------------------|__TRANSFORMATIONS                           
          LoadIdentity(ModelView);                                                                                                    
          Translate(ModelView,   smallPillar_POSITION[0] + moveSet[0], smallPillar_POSITION[1], smallPillar_POSITION[2]+moveSet[2]);                          
          Rotate(ModelView, smallPillar_ROTATE[0], smallPillar_ROTATE[1]+1.0, smallPillar_ROTATE[2], smallPillar_ROTATE[3]);                                                                    
          //Scale(modelView,smallPillar_SCALE,smallPillar_SCALE, smallPillar_SCALE);                                                  
          //-----------------------------------------------------------------------------|__MATRIX_MATH                               
          MultiplyMatrix(ModelViewProjection, Projection, ModelView);                                                                 
          InvertMatrix(ModelViewProjectionInverse, ModelViewProjection);                                                              
          //------------------------------------------------------------------------------|__LIGHT                                    
          LoadIdentity(LightMatrix);                                                                                                  
          InvertMatrix(LightMatrix, ModelView);                                                                                       
          //------------------------------------------------------------------------------|__SHADER                               
 
if(USE_NORMAL_PASS_SHADER)
{       
             #include "../../_SHADERS/GLOBAL_ILLUMINATION/normalPass_RENDER.cpp"                                                                        
}  
           
if(USE_COMPONENT_SHADER)
{          
          //===============================================================================================================================          
          #include  "../../SHADERS/BACKGROUND/goldenSunset_RENDER.cpp"          
          //===============================================================================================================================
}         
          
          glActiveTextureARB(GL_TEXTURE1);                                                                                        
          glBindTexture(GL_TEXTURE_2D,  smallPillar_NORMAL_TEX);          
          glActiveTextureARB(GL_TEXTURE0);                                                                                        
          glBindTexture(GL_TEXTURE_2D,   smallPillar_TEXTURE1);                                                                         
          //-------------------------------------------------------------------------------|__DRAW                                    
          glDrawArrays(GL_TRIANGLES, 0, 93);       
