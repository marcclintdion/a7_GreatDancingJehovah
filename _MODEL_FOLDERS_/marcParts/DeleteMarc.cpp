 
        
        //------------------------------------------------------------
        if(hips_NORMALMAP != 0)
        {
                glDeleteTextures(1, &hips_NORMALMAP);
                hips_NORMALMAP = 0;
        }
        if(hips_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &hips_TEXTUREMAP);
                hips_TEXTUREMAP  = 0;
        }
        if(hips_VBO  != 0)
        {    
                glDeleteBuffers(1, &hips_VBO);
                hips_VBO  = 0;
        }
        //------------------------------------------------------------


        if(torso_NORMALMAP != 0)
        {
                glDeleteTextures(1, &torso_NORMALMAP);
                torso_NORMALMAP = 0;
        }
        if(torso_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &torso_TEXTUREMAP);
                torso_TEXTUREMAP  = 0;
        }        
        if(torso_VBO  != 0)
        {    
                glDeleteBuffers(1, &torso_VBO);
                torso_VBO  = 0;
        }
        //------------------------------------------------------------
        
        if(head_NORMALMAP != 0)
        {
                glDeleteTextures(1, &head_NORMALMAP);
                head_NORMALMAP = 0;
        }
        if(head_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &head_TEXTUREMAP);
                head_TEXTUREMAP  = 0;
        }    
        if(head_neck_VBO  != 0)
        {    
                glDeleteBuffers(1, &head_neck_VBO);
                head_neck_VBO  = 0;
        }
        //------------------------------------------------------------        
       
        if(face_NORMALMAP != 0)
        {
                glDeleteTextures(1, &face_NORMALMAP);
                face_NORMALMAP = 0;
        }
        if(face_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &face_TEXTUREMAP);
                face_TEXTUREMAP  = 0;
        }
         if(face_VBO  != 0)
        {    
                glDeleteBuffers(1, &face_VBO);
                face_VBO  = 0;
        }
        //------------------------------------------------------------       
        
        if(leftUpperArm_NORMALMAP != 0)
        {
                glDeleteTextures(1, &leftUpperArm_NORMALMAP);
                leftUpperArm_NORMALMAP = 0;
        }
        if(leftUpperArm_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &leftUpperArm_TEXTUREMAP);
                leftUpperArm_TEXTUREMAP  = 0;
        }
        if(leftUpperArm_VBO  != 0)
        {    
                glDeleteBuffers(1, &leftUpperArm_VBO);
                leftUpperArm_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(leftLowerArm_NORMALMAP != 0)
        {
                glDeleteTextures(1, &leftLowerArm_NORMALMAP);
                leftLowerArm_NORMALMAP = 0;
        }
        if(leftLowerArm_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &leftLowerArm_TEXTUREMAP);
                leftLowerArm_TEXTUREMAP  = 0;
        }        
        if(leftLowerArm_VBO  != 0)
        {    
                glDeleteBuffers(1, &leftLowerArm_VBO);
                leftLowerArm_VBO  = 0;
        }
        //------------------------------------------------------------
        
        if(leftHand_NORMALMAP != 0)
        {
                glDeleteTextures(1, &leftHand_NORMALMAP);
                leftHand_NORMALMAP = 0;
        }
        if(leftHand_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &leftHand_TEXTUREMAP);
                leftHand_TEXTUREMAP  = 0;
        }    
        if(leftHand_VBO  != 0)
        {    
                glDeleteBuffers(1, &leftHand_VBO);
                leftHand_VBO  = 0;
        }
        //------------------------------------------------------------
        
        if(rightUpperArm_NORMALMAP != 0)
        {
                glDeleteTextures(1, &rightUpperArm_NORMALMAP);
                rightUpperArm_NORMALMAP = 0;
        }
        if(rightUpperArm_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &rightUpperArm_TEXTUREMAP);
                rightUpperArm_TEXTUREMAP  = 0;
        }            
        if(rightUpperArm_VBO  != 0)
        {    
                glDeleteBuffers(1, &rightUpperArm_VBO);
                rightUpperArm_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(rightLowerArm_NORMALMAP != 0)
        {
                glDeleteTextures(1, &rightLowerArm_NORMALMAP);
                rightLowerArm_NORMALMAP = 0;
        }
        if(rightLowerArm_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &rightLowerArm_TEXTUREMAP);
                rightLowerArm_TEXTUREMAP  = 0;
        }     
        if(rightLowerArm_VBO  != 0)
        {    
                glDeleteBuffers(1, &rightLowerArm_VBO);
                rightLowerArm_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(rightHand_NORMALMAP != 0)
        {
                glDeleteTextures(1, &rightHand_NORMALMAP);
                rightHand_NORMALMAP = 0;
        }
        if(rightHand_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &rightHand_TEXTUREMAP);
                rightHand_TEXTUREMAP  = 0;
        }          
        if(rightHand_VBO  != 0)
        {    
                glDeleteBuffers(1, &rightHand_VBO);
                rightHand_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(leftUpperLeg_NORMALMAP != 0)
        {
                glDeleteTextures(1, &leftUpperLeg_NORMALMAP);
                leftUpperLeg_NORMALMAP = 0;
        }
        if(leftUpperLeg_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &leftUpperLeg_TEXTUREMAP);
                leftUpperLeg_TEXTUREMAP  = 0;
        }  
        if(leftUpperLeg_VBO  != 0)
        {    
                glDeleteBuffers(1, &leftUpperLeg_VBO);
                leftUpperLeg_VBO  = 0;
        }
        //------------------------------------------------------------                              
        
        if(leftLowerLeg_NORMALMAP != 0)
        {
                glDeleteTextures(1, &leftLowerLeg_NORMALMAP);
                leftLowerLeg_NORMALMAP = 0;
        }
        if(leftLowerLeg_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &leftLowerLeg_TEXTUREMAP);
                leftLowerLeg_TEXTUREMAP  = 0;
        }          
        if(leftLowerLeg_VBO  != 0)
        {    
                glDeleteBuffers(1, &leftLowerLeg_VBO);
                leftLowerLeg_VBO  = 0;
        }
        //------------------------------------------------------------
        
        if(leftFoot_NORMALMAP != 0)
        {
                glDeleteTextures(1, &leftFoot_NORMALMAP);
                leftFoot_NORMALMAP = 0;
        }
        if(leftFoot_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &leftFoot_TEXTUREMAP);
                leftFoot_TEXTUREMAP  = 0;
        }          
        if(leftFoot_VBO  != 0)
        {    
                glDeleteBuffers(1, &leftFoot_VBO);
                leftFoot_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(rightUpperLeg_NORMALMAP != 0)
        {
                glDeleteTextures(1, &rightUpperLeg_NORMALMAP);
                rightUpperLeg_NORMALMAP = 0;
        }
        if(rightUpperLeg_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &rightUpperLeg_TEXTUREMAP);
                rightUpperLeg_TEXTUREMAP  = 0;
        } 
        if(rightUpperLeg_VBO  != 0)
        {    
                glDeleteBuffers(1, &rightUpperLeg_VBO);
                rightUpperLeg_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(rightLowerLeg_NORMALMAP != 0)
        {
                glDeleteTextures(1, &rightLowerLeg_NORMALMAP);
                rightLowerLeg_NORMALMAP = 0;
        }
        if(rightLowerLeg_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &rightLowerLeg_TEXTUREMAP);
                rightLowerLeg_TEXTUREMAP  = 0;
        } 
        if(rightLowerLeg_VBO  != 0)
        {    
                glDeleteBuffers(1, &rightLowerLeg_VBO);
                rightLowerLeg_VBO  = 0;
        }
        //------------------------------------------------------------        
        
        if(rightFoot_NORMALMAP != 0)
        {
                glDeleteTextures(1, &rightFoot_NORMALMAP);
                rightFoot_NORMALMAP = 0;
        }
        if(rightFoot_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &rightFoot_TEXTUREMAP);
                rightFoot_TEXTUREMAP  = 0;
        }       
        if(rightFoot_VBO  != 0)
        {    
                glDeleteBuffers(1, &rightFoot_VBO);
                rightFoot_VBO  = 0;
        }
        //------------------------------------------------------------   




