

              glUseProgramObjectARB(gaussianBlurHorizontalPass_SHADER);


              glUniform1fARB( UNIFORM_shininess_gaussianBlurHorizontalPass, shininess_gaussianBlurHorizontalPass);
              glUniform1fARB( UNIFORM_counter1_gaussianBlurHorizontalPass, gaussianBlurHorizontalPass_counter1);
              glUniform1fARB( UNIFORM_counter2_gaussianBlurHorizontalPass, gaussianBlurHorizontalPass_counter2);
              glUniform1fARB( UNIFORM_counter3_gaussianBlurHorizontalPass, gaussianBlurHorizontalPass_counter3);
              glUniform1fARB( UNIFORM_counter4_gaussianBlurHorizontalPass, gaussianBlurHorizontalPass_counter4);


              glBindBufferARB(GL_ARRAY_BUFFER_ARB, gaussianBlurHorizontalPass_vboID);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(gaussianBlurHorizontalPass_VERT) + sizeof(gaussianBlurHorizontalPass_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(gaussianBlurHorizontalPass_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);


              textureID;
              textureID     = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[0]);


              glDrawArrays(GL_TRIANGLES, 0, 6);


              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

