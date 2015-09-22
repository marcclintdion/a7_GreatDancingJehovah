if (keys[VK_PRIOR])
{
        // mainBodyPosition[1]                   +=   0.02;
         moveSet[1]  -= 0.0393*frameRateAdjustment;

}	
if (keys[VK_NEXT])
{
         //mainBodyPosition[1]                   -=   0.02;
         moveSet[1]  += 0.0393*frameRateAdjustment;
} 
    
if (keys[VK_PRIOR] && keys[VK_SHIFT])
{
        // mainBodyPosition[1]                   +=   0.02;
         moveSet[1]  -= 0.0393*frameRateAdjustment*10.0;

}	
if (keys[VK_NEXT] && keys[VK_SHIFT])
{
         //mainBodyPosition[1]                   -=   0.02;
         moveSet[1]  += 0.0393*frameRateAdjustment*10.0;
}    
 //--------------------------------------------------------------------------------------------------   

    
    if (!keys[VK_SPACE] && !marcJumping)
	{    
          spaceBarIsPressed = false;
    }
    if (keys[VK_SPACE] && !spaceBarIsPressed)
	{
           spaceBarIsPressed = true;
           marcJumping = true;
           resetAnimation = true;                    
    }     
    
    if (keys[VK_RIGHT] &! keys[VK_UP] &! keys[VK_DOWN])
	{
                         if(marcModel_ROTATE[3] >= 360.0)
                         {
                                 marcModel_ROTATE[3] -= 360.0;
                         }
                         if(marcModel_ROTATE[3] < 0.0)
                         {
                                 marcModel_ROTATE[3] += 360.0;
                         }            

           if(marcModel_ROTATE[3] > 90.0 && marcModel_ROTATE[3] <= 270.0)
           {
                 marcModel_ROTATE[3] -= 8.0 * frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 90.0 && marcModel_ROTATE[3] >= 0.0 || marcModel_ROTATE[3] > 270.0 && marcModel_ROTATE[3] < 360.0)
           {
                 marcModel_ROTATE[3] += 8.0 * frameRateAdjustment;
           }
                      
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                  CollisionCheck_RIGHT(boundingBox_MAIN_CHARACTER_left_edge,   boundingBox_MAIN_CHARACTER_right_edge,
                                       boundingBox_MAIN_CHARACTER_lower_edge,  boundingBox_MAIN_CHARACTER_upper_edge,
                                       boundingBox_MAIN_CHARACTER_near_edge,   boundingBox_MAIN_CHARACTER_far_edge);                
                  if(RIGHT == true)               
			      {
                           marcWalking = true;  
                           moveSet[0]  -= 0.0393*frameRateAdjustment;

                  }
                  if(RIGHT == true && keys[VK_SHIFT])               
			      {
                           marcWalking = true;  
                           moveSet[0]  -= 0.0393*frameRateAdjustment*10.0;

                  }                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    
    }
//--------------------------------------------------------------    
    if (keys[VK_LEFT] &! keys[VK_UP] &! keys[VK_DOWN])
	{
                         if(marcModel_ROTATE[3] >= 360.0)
                         {
                                 marcModel_ROTATE[3] -= 360.0;
                         }
                         if(marcModel_ROTATE[3] <= 0.0)
                         {
                                 marcModel_ROTATE[3] += 360.0;
                         }          
           
           if(marcModel_ROTATE[3] == 0.0)
           {
                 marcModel_ROTATE[3] += 360.0;
           }
           if(marcModel_ROTATE[3] >= 270.0 && marcModel_ROTATE[3] <= 360.0 || marcModel_ROTATE[3] >= 0.0 && marcModel_ROTATE[3] <= 90.0)
           {
                 marcModel_ROTATE[3] -= 8.0* frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 270.0  && marcModel_ROTATE[3]  >= 90.0)
           {
                 marcModel_ROTATE[3] += 8.0* frameRateAdjustment;
           }           
          
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           
                  CollisionCheck_LEFT(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,    
                                      boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                      boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge); 
                  if(LEFT == true)              
                  {             
                                marcWalking = true;                    
                                moveSet[0]  += 0.0393*frameRateAdjustment;

                  }
                  if(LEFT == true && keys[VK_SHIFT])              
                  {             
                                marcWalking = true;                    
                                moveSet[0]  += 0.0393*frameRateAdjustment*10.0;

                  }                  
                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    }
//--------------------------------------------------------------    
    if (keys[VK_UP] &! keys[VK_LEFT] &! keys[VK_RIGHT])
	{
                         if(marcModel_ROTATE[3] >= 360)
                         {
                                 marcModel_ROTATE[3] -= 360;
                         }
                         if(marcModel_ROTATE[3] < 0)
                         {
                                 marcModel_ROTATE[3] += 360;
                         }            
           
           if(marcModel_ROTATE[3] >= 180 && marcModel_ROTATE[3] < 360)
           {
                 marcModel_ROTATE[3] -= 4* frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 180 && marcModel_ROTATE[3] >= 0.0)
           {
                 marcModel_ROTATE[3] += 4* frameRateAdjustment;
           }
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           
                  CollisionCheck_UP(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,    
                                    boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                    boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge);  
                  if(UP == true)            
			      { 
                          marcWalking = true;                     
                          moveSet[2]            += 0.0393*frameRateAdjustment;
        
                  }
                  if(UP == true && keys[VK_SHIFT])            
			      { 
                          marcWalking = true;                     
                          moveSet[2]            += 0.0393*frameRateAdjustment*10.0;
        
                  }                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    }	
//--------------------------------------------------------------    
    if (keys[VK_DOWN] &! keys[VK_LEFT] &! keys[VK_RIGHT])
	{
                         if(marcModel_ROTATE[3] >= 360)
                         {
                                 marcModel_ROTATE[3] -= 360;
                         }
                         if(marcModel_ROTATE[3] < 0)
                         {
                                 marcModel_ROTATE[3] += 360;
                         } 
           
           if(marcModel_ROTATE[3] <= 3)
           {
                 marcModel_ROTATE[3] = 0;
           }
           if(marcModel_ROTATE[3] >= 357)
           {
                 marcModel_ROTATE[3] = 0;
           }            
           
           if(marcModel_ROTATE[3] < 360 && marcModel_ROTATE[3] > 180.0)
           {
                 marcModel_ROTATE[3] += 4* frameRateAdjustment;
           }           
           if(marcModel_ROTATE[3] > 0.0 && marcModel_ROTATE[3] <= 180.0)
           {
                 marcModel_ROTATE[3] -= 4* frameRateAdjustment;
           }

//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            
                  CollisionCheck_DOWN(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,   
                                      boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                      boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge); 
                  if(DOWN == true)              
			      {              
                                 marcWalking = true;                    
                                 moveSet[2]           -= 0.0393*frameRateAdjustment;

                  }
                  if(DOWN == true && keys[VK_SHIFT])              
			      {              
                                 marcWalking = true;                    
                                 moveSet[2]           -= 0.0393*frameRateAdjustment*10.0;

                  }                  
                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    }      
//--------------------------------------------------------------  
    if (keys[VK_DOWN] && keys[VK_RIGHT])
	{
                         if(marcModel_ROTATE[3] >= 360)
                         {
                                 marcModel_ROTATE[3] -= 360;
                         }
                         if(marcModel_ROTATE[3] < 0)
                         {
                                 marcModel_ROTATE[3] += 360;
                         } 
           
           if(marcModel_ROTATE[3] > 45 && marcModel_ROTATE[3] <= 225)
           {
                 marcModel_ROTATE[3] -= 4* frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 45 && marcModel_ROTATE[3] >= 0.0 || marcModel_ROTATE[3] >= 225 && marcModel_ROTATE[3] <= 360)
           {
                 marcModel_ROTATE[3] += 4* frameRateAdjustment;
           }
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            
                  CollisionCheck_DOWN(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,   
                                      boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                      boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge);
                  
                  CollisionCheck_RIGHT(boundingBox_MAIN_CHARACTER_left_edge,   boundingBox_MAIN_CHARACTER_right_edge,
                                       boundingBox_MAIN_CHARACTER_lower_edge,  boundingBox_MAIN_CHARACTER_upper_edge,
                                       boundingBox_MAIN_CHARACTER_near_edge,   boundingBox_MAIN_CHARACTER_far_edge);                   
                  
                  if(DOWN == true  && RIGHT == true )              
			      {              
                                 marcWalking = true;                    
                                 moveSet[0]  -= .03*frameRateAdjustment;
                                 moveSet[2]  -= .03*frameRateAdjustment;
        
                  }
                  if(DOWN == true  && RIGHT == true  && keys[VK_SHIFT])              
			      {              
                                 marcWalking = true;                    
                                 moveSet[0]  -= .03*frameRateAdjustment*10.0;
                                 moveSet[2]  -= .03*frameRateAdjustment*10.0;
        
                  }                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           
    }      
//--------------------------------------------------------------    
    if (keys[VK_UP] && keys[VK_RIGHT])
	{
                         if(marcModel_ROTATE[3] >= 360)
                         {
                                 marcModel_ROTATE[3] -= 360;
                         }
                         if(marcModel_ROTATE[3] < 0)
                         {
                                 marcModel_ROTATE[3] += 360;
                         } 
           
           if(marcModel_ROTATE[3] > 135 && marcModel_ROTATE[3] <= 315)
           {
                 marcModel_ROTATE[3] -= 4* frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 135 && marcModel_ROTATE[3] >= 0.0 || marcModel_ROTATE[3] >= 315 && marcModel_ROTATE[3] <= 360)
           {
                 marcModel_ROTATE[3] += 4* frameRateAdjustment;
           }
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            
                  CollisionCheck_UP(boundingBox_MAIN_CHARACTER_left_edge,   boundingBox_MAIN_CHARACTER_right_edge,  
                                    boundingBox_MAIN_CHARACTER_lower_edge,  boundingBox_MAIN_CHARACTER_upper_edge,
                                    boundingBox_MAIN_CHARACTER_near_edge,   boundingBox_MAIN_CHARACTER_far_edge); 
                  
                  CollisionCheck_RIGHT(boundingBox_MAIN_CHARACTER_left_edge,   boundingBox_MAIN_CHARACTER_right_edge,
                                       boundingBox_MAIN_CHARACTER_lower_edge,  boundingBox_MAIN_CHARACTER_upper_edge,
                                       boundingBox_MAIN_CHARACTER_near_edge,   boundingBox_MAIN_CHARACTER_far_edge);                  
                  
                  if(UP == true && RIGHT == true )            
			      {            
                               marcWalking = true;                    
                               moveSet[0]  -= .03*frameRateAdjustment;
                               moveSet[2]  += .03*frameRateAdjustment;
    
                  }
                  if(UP == true && RIGHT == true  && keys[VK_SHIFT])            
			      {            
                               marcWalking = true;                    
                               moveSet[0]  -= .03*frameRateAdjustment*10.0;
                               moveSet[2]  += .03*frameRateAdjustment*10.0;
    
                  }                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    }    
//--------------------------------------------------------------    
    if (keys[VK_UP] && keys[VK_LEFT])
	{
                         if(marcModel_ROTATE[3] >= 360)
                         {
                                 marcModel_ROTATE[3] -= 360;
                         }
                         if(marcModel_ROTATE[3] < 0)
                         {
                                 marcModel_ROTATE[3] += 360;
                         } 
           
           if(marcModel_ROTATE[3] > 225 && marcModel_ROTATE[3] <= 360 || marcModel_ROTATE[3] <= 45 && marcModel_ROTATE[3] >= 0)
           {
                 marcModel_ROTATE[3] -= 4* frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 225 && marcModel_ROTATE[3] >= 45)
           {
                 marcModel_ROTATE[3] += 4* frameRateAdjustment;
           }
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            
                  CollisionCheck_UP(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,
                                    boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge, 
                                    boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge);
                  
                  CollisionCheck_LEFT(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,    
                                      boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                      boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge); 
                                      
                  
                  if(UP == true && LEFT == true)            
			      {            
                               marcWalking = true;                    
                               moveSet[0]  += .03*frameRateAdjustment;
                               moveSet[2]  += .03*frameRateAdjustment;
    
                  }
                  if(UP == true && LEFT == true && keys[VK_SHIFT])            
			      {            
                               marcWalking = true;                    
                               moveSet[0]  += .03*frameRateAdjustment*10.0;
                               moveSet[2]  += .03*frameRateAdjustment*10.0;
    
                  }                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    }      
//--------------------------------------------------------------    
    if (keys[VK_LEFT] && keys[VK_DOWN])
	{
                         if(marcModel_ROTATE[3] >= 360)
                         {
                                 marcModel_ROTATE[3] -= 360;
                         }
                         if(marcModel_ROTATE[3] < 0)
                         {
                                 marcModel_ROTATE[3] += 360;
                         } 
           
           if(marcModel_ROTATE[3] > 315 && marcModel_ROTATE[3] <= 360 || marcModel_ROTATE[3] <= 135 && marcModel_ROTATE[3] >= 0)
           {
                 marcModel_ROTATE[3] -= 4* frameRateAdjustment;
           }
           if(marcModel_ROTATE[3] < 315 && marcModel_ROTATE[3] >= 135)
           {
                 marcModel_ROTATE[3] += 4* frameRateAdjustment;
           }
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            
                  CollisionCheck_LEFT(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,
                                      boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                      boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge);
                  
                  CollisionCheck_DOWN(boundingBox_MAIN_CHARACTER_left_edge,  boundingBox_MAIN_CHARACTER_right_edge,   
                                      boundingBox_MAIN_CHARACTER_lower_edge, boundingBox_MAIN_CHARACTER_upper_edge,
                                      boundingBox_MAIN_CHARACTER_near_edge,  boundingBox_MAIN_CHARACTER_far_edge);                  
                  
                  if(LEFT == true && DOWN == true)              
                  {             
                                marcWalking  = true;                    
                                moveSet[0]  += .03*frameRateAdjustment;
                                moveSet[2]  -= .03*frameRateAdjustment;
           
                  }
                  if(LEFT == true && DOWN == true && keys[VK_SHIFT])              
                  {             
                                marcWalking  = true;                    
                                moveSet[0]  += .03*frameRateAdjustment*10.0;
                                moveSet[2]  -= .03*frameRateAdjustment*10.0;
           
                  }                  
                  
//____%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    }     
    //--------------------------------------------------------------------------------------------------
    if (!keys[VK_RIGHT] && !keys[VK_LEFT] && !keys[VK_UP] && !keys[VK_DOWN])
	{
           marcWalking = false;  
    }        
    //===================================================================================================
    //===================================================================================================    
    //===================================================================================================
    //=================================================================================================== 
