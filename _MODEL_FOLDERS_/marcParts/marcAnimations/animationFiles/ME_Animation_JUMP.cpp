mainBodyPosition_setSelectionLimit  = 6;
mainBodyPosition_SelectionCount     = 6;


mainBodyPosition_setSelectionLimit  = 6;
mainBodyPosition_SelectionCount     = 6;


setSelectionLimit_HEAD              = 6;
SelectionCount_HEAD                 = 6;


setSelectionLimit_TORSO             = 6;
SelectionCount_TORSO                = 6;


setSelectionLimit_HIPS              = 6;
SelectionCount_HIPS                 = 6;


setSelectionLimit_LEFT_ARM          = 6;
SelectionCount_LEFT_ARM             = 6;


setSelectionLimit_RIGHT_ARM         = 6;
SelectionCount_RIGHT_ARM            = 6;


setSelectionLimit_LEFT_LEG          = 6;
SelectionCount_LEFT_LEG             = 6;


setSelectionLimit_RIGHT_LEG         = 6;
SelectionCount_RIGHT_LEG            = 6;


if(mainBodyPosition_setSelection == 1)
{
    mainBodyPosition_MOVE_FRAMEA[0]     = 0.003;
    mainBodyPosition_MOVE_FRAMEA[1]     = -0.001;
    mainBodyPosition_MOVE_FRAMEA[2]     = 0.003;
    mainBodyPosition_MOVE_FRAMEB[0]     = 0.018;
    mainBodyPosition_MOVE_FRAMEB[1]     = -0.146;
    mainBodyPosition_MOVE_FRAMEB[2]     = -0.077;
}
if(setSelection_LEFT_ARM == 1)
{    leftUpperArm_ROTATE_FRAMEA[3]   = 0;
    leftUpperArm_ROTATE_FRAMEA[0]   = 1;
    leftUpperArm_ROTATE_FRAMEA[1]   = 0;
    leftUpperArm_ROTATE_FRAMEA[2]   = 0;
    leftUpperArm_ROTATE_FRAMEB[3]   = 35;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEA[3]   = 0;
    leftLowerArm_ROTATE_FRAMEA[0]   = 1;
    leftLowerArm_ROTATE_FRAMEA[1]   = 0;
    leftLowerArm_ROTATE_FRAMEA[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = -70;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_RIGHT_ARM == 1)
{    rightUpperArm_ROTATE_FRAMEA[3]   = 0;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightUpperArm_ROTATE_FRAMEB[3]   = 35;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]   = 0;
    rightLowerArm_ROTATE_FRAMEA[0]   = 1;
    rightLowerArm_ROTATE_FRAMEA[1]   = 0;
    rightLowerArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -70;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_LEFT_LEG == 1)
{    leftUpperLeg_ROTATE_FRAMEA[3]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[3]   = -73;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 97;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]       = 0;
    leftFoot_ROTATE_FRAMEA[0]       = 1;
    leftFoot_ROTATE_FRAMEA[1]       = 0;
    leftFoot_ROTATE_FRAMEA[2]       = 0;
    leftFoot_ROTATE_FRAMEB[3]       = 0;
    leftFoot_ROTATE_FRAMEB[0]       = 1;
    leftFoot_ROTATE_FRAMEB[1]       = 0;
    leftFoot_ROTATE_FRAMEB[2]       = 0;
}
if(setSelection_RIGHT_LEG == 1)
{    rightUpperLeg_ROTATE_FRAMEA[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[3]   = -67;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 92;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = 0;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -14;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HEAD == 1)
{
    head_ROTATE_FRAMEA[3]   = 4;
    head_ROTATE_FRAMEA[0]   = 0;
    head_ROTATE_FRAMEA[1]   = 1;
    head_ROTATE_FRAMEA[2]   = 0;
    head_ROTATE_FRAMEB[3]   = -27;
    head_ROTATE_FRAMEB[0]   = 0.280001;
    head_ROTATE_FRAMEB[1]   = 1e-006;
    head_ROTATE_FRAMEB[2]   = 1e-006;
}
if(setSelection_TORSO == 1)
{
    torso_ROTATE_FRAMEA[3]   = 0;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
    torso_ROTATE_FRAMEB[3]   = 35;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HIPS == 1)
{
    hips_ROTATE_FRAMEA[3]   = 0;
    hips_ROTATE_FRAMEA[0]   = 0;
    hips_ROTATE_FRAMEA[1]   = 1;
    hips_ROTATE_FRAMEA[2]   = 0;
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
if(mainBodyPosition_setSelection == 2)
{
    mainBodyPosition_MOVE_FRAMEA[0]         = 0.018;
    mainBodyPosition_MOVE_FRAMEA[1]         = -0.146;
    mainBodyPosition_MOVE_FRAMEA[2]         = -0.077;

   if(mainBodyPosition_SelectionCount == 2)
{
   mainBodyPosition_MOVE_FRAMEB[0]          = 0.003;
   mainBodyPosition_MOVE_FRAMEB[1]          = -0.001;
   mainBodyPosition_MOVE_FRAMEB[2]          = 0.003;
}
     else 
    {
    mainBodyPosition_MOVE_FRAMEB[0]         = -0.01;
    mainBodyPosition_MOVE_FRAMEB[1]         = 0.393998;
    mainBodyPosition_MOVE_FRAMEB[2]         = -0.03;
}
}
if(setSelection_LEFT_ARM == 2)
{
    leftUpperArm_ROTATE_FRAMEA[3]     = 35;
    leftUpperArm_ROTATE_FRAMEA[0]     = 1;
    leftUpperArm_ROTATE_FRAMEA[1]     = 0;
    leftUpperArm_ROTATE_FRAMEA[2]     = 0;
    leftLowerArm_ROTATE_FRAMEA[3]      = -70;
    leftLowerArm_ROTATE_FRAMEA[0]      = 1;
    leftLowerArm_ROTATE_FRAMEA[1]      = 0;
    leftLowerArm_ROTATE_FRAMEA[2]      = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_ARM == 2)
    {
    leftUpperArm_ROTATE_FRAMEB[3]     = 0;
    leftUpperArm_ROTATE_FRAMEB[0]     = 1;
    leftUpperArm_ROTATE_FRAMEB[1]     = 0;
    leftUpperArm_ROTATE_FRAMEB[2]     = 0;
    leftLowerArm_ROTATE_FRAMEB[3]      = 0;
    leftLowerArm_ROTATE_FRAMEB[0]      = 1;
    leftLowerArm_ROTATE_FRAMEB[1]      = 0;
    leftLowerArm_ROTATE_FRAMEB[2]      = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
     else 
    {
    leftUpperArm_ROTATE_FRAMEB[3]      = -80;
    leftUpperArm_ROTATE_FRAMEB[0]      = 1;
    leftUpperArm_ROTATE_FRAMEB[1]      = 0;
    leftUpperArm_ROTATE_FRAMEB[2]      = 0;
    leftLowerArm_ROTATE_FRAMEB[3]       = -48;
    leftLowerArm_ROTATE_FRAMEB[0]       = 1;
    leftLowerArm_ROTATE_FRAMEB[1]       = 0;
    leftLowerArm_ROTATE_FRAMEB[2]       = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
}
if(setSelection_RIGHT_ARM == 2)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = 35;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -70;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3]   = 0;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_ARM == 2)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 0;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 0;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -71;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -59;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = -1;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 2)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -73;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 97;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = 0;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 2)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 0;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -20;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 46;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 9;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 2)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -67;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 92;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -14;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 2)
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 0;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 9;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 28;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 2)
{
    head_ROTATE_FRAMEA[3]   = -27;
    head_ROTATE_FRAMEA[0]   = 0.280001;
    head_ROTATE_FRAMEA[1]   = 1e-006;
    head_ROTATE_FRAMEA[2]   = 1e-006;
   if(SelectionCount_HEAD == 2)
{
    head_ROTATE_FRAMEB[3]   = 4;
    head_ROTATE_FRAMEB[0]   = 0;
    head_ROTATE_FRAMEB[1]   = 1;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    head_ROTATE_FRAMEB[3]   = -27;
    head_ROTATE_FRAMEB[0]   = 0.280001;
    head_ROTATE_FRAMEB[1]   = 1e-006;
    head_ROTATE_FRAMEB[2]   = 1e-006;
}
}
if(setSelection_TORSO == 2)
{
    torso_ROTATE_FRAMEA[3]   = 35;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_TORSO == 2)
{
    torso_ROTATE_FRAMEB[3]   = 0;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    torso_ROTATE_FRAMEB[3]   = 13;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 2)
{
    hips_ROTATE_FRAMEA[3]   = 0;
    hips_ROTATE_FRAMEA[0]   = 0;
    hips_ROTATE_FRAMEA[1]   = 1;
    hips_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HIPS == 2)
{
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 3)
{
    mainBodyPosition_MOVE_FRAMEA[0]      = -0.01;
    mainBodyPosition_MOVE_FRAMEA[1]      = 0.393998;
    mainBodyPosition_MOVE_FRAMEA[2]      = -0.03;

     if(mainBodyPosition_SelectionCount == 3)
    {
    mainBodyPosition_MOVE_FRAMEB[0]      = 0.003;
    mainBodyPosition_MOVE_FRAMEB[1]      = -0.001;
    mainBodyPosition_MOVE_FRAMEB[2]      = 0.003;
}
     else
    {
    mainBodyPosition_MOVE_FRAMEB[0]      = -0.01;
    mainBodyPosition_MOVE_FRAMEB[1]      = 0.619996;
    mainBodyPosition_MOVE_FRAMEB[2]      = 3.49246e-009;
}
}
if(setSelection_LEFT_ARM == 3)
{
    leftUpperArm_ROTATE_FRAMEA[3]   = -80;
    leftUpperArm_ROTATE_FRAMEA[0]   = 1;
    leftUpperArm_ROTATE_FRAMEA[1]   = 0;
    leftUpperArm_ROTATE_FRAMEA[2]   = 0;
    leftLowerArm_ROTATE_FRAMEA[3]    = -48;
    leftLowerArm_ROTATE_FRAMEA[0]    = 1;
    leftLowerArm_ROTATE_FRAMEA[1]    = 0;
    leftLowerArm_ROTATE_FRAMEA[2]    = 0;
    leftHand_ROTATE_FRAMEA[3] = 0;
    leftHand_ROTATE_FRAMEA[0] = 1;
    leftHand_ROTATE_FRAMEA[1] = 0;
    leftHand_ROTATE_FRAMEA[2] = 0;

     if(SelectionCount_LEFT_ARM == 3)
    {
    leftUpperArm_ROTATE_FRAMEB[3]   = 0;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = 0;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    leftUpperArm_ROTATE_FRAMEB[3]   = -112;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = -44;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_ARM == 3)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = -71;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -59;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3] = -1;
    rightHand_ROTATE_FRAMEA[0] = 1;
    rightHand_ROTATE_FRAMEA[1] = 0;
    rightHand_ROTATE_FRAMEA[2] = 0;

     if(SelectionCount_RIGHT_ARM == 3)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 0;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 0;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = -112;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -41;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = -1;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 3)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -20;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 46;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = 9;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 3)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 0;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -88;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 140;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -44;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 3)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 9;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = 28;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 3)
    {
     rightUpperLeg_ROTATE_FRAMEB[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 0;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -91;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 135;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -31;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 3)
{
    head_ROTATE_FRAMEA[3]   = -27;
    head_ROTATE_FRAMEA[0]   = 0.280001;
    head_ROTATE_FRAMEA[1]   = 1e-006;
    head_ROTATE_FRAMEA[2]   = 1e-006;
     if(SelectionCount_HEAD == 3)
    {
    head_ROTATE_FRAMEB[3]   = 4;
    head_ROTATE_FRAMEB[0]   = 0;
    head_ROTATE_FRAMEB[1]   = 1;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    head_ROTATE_FRAMEB[3]   = -6;
    head_ROTATE_FRAMEB[0]   = 0.280001;
    head_ROTATE_FRAMEB[1]   = 1e-006;
    head_ROTATE_FRAMEB[2]   = 1e-006;
}
}
if(setSelection_TORSO == 3)
{
    torso_ROTATE_FRAMEA[3]   = 13;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_TORSO == 3)
    {
    torso_ROTATE_FRAMEB[3]   = 0;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    torso_ROTATE_FRAMEB[3]   = -5;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 3)
{
    hips_ROTATE_FRAMEA[3]   = 0;
    hips_ROTATE_FRAMEA[0]   = 0;
    hips_ROTATE_FRAMEA[1]   = 1;
    hips_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_HIPS == 3)
    {
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else
    {
    hips_ROTATE_FRAMEB[3]   = 2;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 4)
{
    mainBodyPosition_MOVE_FRAMEA[0]         = -0.01;
    mainBodyPosition_MOVE_FRAMEA[1]         = 0.619996;
    mainBodyPosition_MOVE_FRAMEA[2]         = 3.49246e-009;

   if(mainBodyPosition_SelectionCount == 4)
{
   mainBodyPosition_MOVE_FRAMEB[0]          = 0.003;
   mainBodyPosition_MOVE_FRAMEB[1]          = -0.001;
   mainBodyPosition_MOVE_FRAMEB[2]          = 0.003;
}
     else 
    {
    mainBodyPosition_MOVE_FRAMEB[0]         = -0.01;
    mainBodyPosition_MOVE_FRAMEB[1]         = -0.116;
    mainBodyPosition_MOVE_FRAMEB[2]         = 3.49246e-009;
}
}
if(setSelection_LEFT_ARM == 4)
{
    leftUpperArm_ROTATE_FRAMEA[3]     = -112;
    leftUpperArm_ROTATE_FRAMEA[0]     = 1;
    leftUpperArm_ROTATE_FRAMEA[1]     = 0;
    leftUpperArm_ROTATE_FRAMEA[2]     = 0;
    leftLowerArm_ROTATE_FRAMEA[3]      = -44;
    leftLowerArm_ROTATE_FRAMEA[0]      = 1;
    leftLowerArm_ROTATE_FRAMEA[1]      = 0;
    leftLowerArm_ROTATE_FRAMEA[2]      = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_ARM == 4)
    {
    leftUpperArm_ROTATE_FRAMEB[3]     = 0;
    leftUpperArm_ROTATE_FRAMEB[0]     = 1;
    leftUpperArm_ROTATE_FRAMEB[1]     = 0;
    leftUpperArm_ROTATE_FRAMEB[2]     = 0;
    leftLowerArm_ROTATE_FRAMEB[3]      = 0;
    leftLowerArm_ROTATE_FRAMEB[0]      = 1;
    leftLowerArm_ROTATE_FRAMEB[1]      = 0;
    leftLowerArm_ROTATE_FRAMEB[2]      = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
     else 
    {
    leftUpperArm_ROTATE_FRAMEB[3]      = 30;
    leftUpperArm_ROTATE_FRAMEB[0]      = 1;
    leftUpperArm_ROTATE_FRAMEB[1]      = 0;
    leftUpperArm_ROTATE_FRAMEB[2]      = 0;
    leftLowerArm_ROTATE_FRAMEB[3]       = 7;
    leftLowerArm_ROTATE_FRAMEB[0]       = 1;
    leftLowerArm_ROTATE_FRAMEB[1]       = 0;
    leftLowerArm_ROTATE_FRAMEB[2]       = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
}
if(setSelection_RIGHT_ARM == 4)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = -112;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -41;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3]   = -1;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_ARM == 4)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 0;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 0;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 38;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -3;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = -1;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 4)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -88;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 140;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = -44;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 4)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 0;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -57;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 110;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -50;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 4)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -91;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 135;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -31;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 4)
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 0;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -55;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 110;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -45;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 4)
{
    head_ROTATE_FRAMEA[3]   = -6;
    head_ROTATE_FRAMEA[0]   = 0.280001;
    head_ROTATE_FRAMEA[1]   = 1e-006;
    head_ROTATE_FRAMEA[2]   = 1e-006;
   if(SelectionCount_HEAD == 4)
{
    head_ROTATE_FRAMEB[3]   = 4;
    head_ROTATE_FRAMEB[0]   = 0;
    head_ROTATE_FRAMEB[1]   = 1;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    head_ROTATE_FRAMEB[3]   = 12;
    head_ROTATE_FRAMEB[0]   = 0.280001;
    head_ROTATE_FRAMEB[1]   = 1e-006;
    head_ROTATE_FRAMEB[2]   = 1e-006;
}
}
if(setSelection_TORSO == 4)
{
    torso_ROTATE_FRAMEA[3]   = -5;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_TORSO == 4)
{
    torso_ROTATE_FRAMEB[3]   = 0;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    torso_ROTATE_FRAMEB[3]   = 17;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 4)
{
    hips_ROTATE_FRAMEA[3]   = 2;
    hips_ROTATE_FRAMEA[0]   = 0;
    hips_ROTATE_FRAMEA[1]   = 1;
    hips_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HIPS == 4)
{
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    hips_ROTATE_FRAMEB[3]   = 2;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 5)
{
    mainBodyPosition_MOVE_FRAMEA[0]         = -0.01;
    mainBodyPosition_MOVE_FRAMEA[1]         = -0.116;
    mainBodyPosition_MOVE_FRAMEA[2]         = 3.49246e-009;

   if(mainBodyPosition_SelectionCount == 5)
{
   mainBodyPosition_MOVE_FRAMEB[0]          = 0.003;
   mainBodyPosition_MOVE_FRAMEB[1]          = -0.001;
   mainBodyPosition_MOVE_FRAMEB[2]          = 0.003;
}
     else 
    {
    mainBodyPosition_MOVE_FRAMEB[0]         = -0.002;
    mainBodyPosition_MOVE_FRAMEB[1]         = -0.089;
    mainBodyPosition_MOVE_FRAMEB[2]         = 3.49246e-009;
}
}
if(setSelection_LEFT_ARM == 5)
{
    leftUpperArm_ROTATE_FRAMEA[3]     = 30;
    leftUpperArm_ROTATE_FRAMEA[0]     = 1;
    leftUpperArm_ROTATE_FRAMEA[1]     = 0;
    leftUpperArm_ROTATE_FRAMEA[2]     = 0;
    leftLowerArm_ROTATE_FRAMEA[3]      = 7;
    leftLowerArm_ROTATE_FRAMEA[0]      = 1;
    leftLowerArm_ROTATE_FRAMEA[1]      = 0;
    leftLowerArm_ROTATE_FRAMEA[2]      = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_ARM == 5)
    {
    leftUpperArm_ROTATE_FRAMEB[3]     = 0;
    leftUpperArm_ROTATE_FRAMEB[0]     = 1;
    leftUpperArm_ROTATE_FRAMEB[1]     = 0;
    leftUpperArm_ROTATE_FRAMEB[2]     = 0;
    leftLowerArm_ROTATE_FRAMEB[3]      = 0;
    leftLowerArm_ROTATE_FRAMEB[0]      = 1;
    leftLowerArm_ROTATE_FRAMEB[1]      = 0;
    leftLowerArm_ROTATE_FRAMEB[2]      = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
     else 
    {
    leftUpperArm_ROTATE_FRAMEB[3]      = 23;
    leftUpperArm_ROTATE_FRAMEB[0]      = 1;
    leftUpperArm_ROTATE_FRAMEB[1]      = 0;
    leftUpperArm_ROTATE_FRAMEB[2]      = 0;
    leftLowerArm_ROTATE_FRAMEB[3]       = 7;
    leftLowerArm_ROTATE_FRAMEB[0]       = 1;
    leftLowerArm_ROTATE_FRAMEB[1]       = 0;
    leftLowerArm_ROTATE_FRAMEB[2]       = 0;
    leftHand_ROTATE_FRAMEB[3]    = 0;
    leftHand_ROTATE_FRAMEB[0]    = 1;
    leftHand_ROTATE_FRAMEB[1]    = 0;
    leftHand_ROTATE_FRAMEB[2]    = 0;
}
}
if(setSelection_RIGHT_ARM == 5)
{
    rightUpperArm_ROTATE_FRAMEA[3]   = 38;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]    = -3;
    rightLowerArm_ROTATE_FRAMEA[0]    = 1;
    rightLowerArm_ROTATE_FRAMEA[1]    = 0;
    rightLowerArm_ROTATE_FRAMEA[2]    = 0;
    rightHand_ROTATE_FRAMEA[3]   = -1;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_ARM == 5)
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 0;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 0;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperArm_ROTATE_FRAMEB[3]   = 29;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = -3;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = -1;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_LEFT_LEG == 5)
{
    leftUpperLeg_ROTATE_FRAMEA[3]   = -57;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 110;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]   = -50;
    leftFoot_ROTATE_FRAMEA[0]   = 1;
    leftFoot_ROTATE_FRAMEA[1]   = 0;
    leftFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_LEFT_LEG == 5)
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = 0;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    leftUpperLeg_ROTATE_FRAMEB[3]   = -44;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 66;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEB[3]   = -11;
    leftFoot_ROTATE_FRAMEB[0]   = 1;
    leftFoot_ROTATE_FRAMEB[1]   = 0;
    leftFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_RIGHT_LEG == 5)
{
    rightUpperLeg_ROTATE_FRAMEA[3]   = -55;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 110;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -45;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
     if(SelectionCount_RIGHT_LEG == 5)
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 0;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    rightUpperLeg_ROTATE_FRAMEB[3]   = -46;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 67;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = -5;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HEAD == 5)
{
    head_ROTATE_FRAMEA[3]   = 12;
    head_ROTATE_FRAMEA[0]   = 0.280001;
    head_ROTATE_FRAMEA[1]   = 1e-006;
    head_ROTATE_FRAMEA[2]   = 1e-006;
   if(SelectionCount_HEAD == 5)
{
    head_ROTATE_FRAMEB[3]   = 4;
    head_ROTATE_FRAMEB[0]   = 0;
    head_ROTATE_FRAMEB[1]   = 1;
    head_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    head_ROTATE_FRAMEB[3]   = -1;
    head_ROTATE_FRAMEB[0]   = 0.280001;
    head_ROTATE_FRAMEB[1]   = 1e-006;
    head_ROTATE_FRAMEB[2]   = 1e-006;
}
}
if(setSelection_TORSO == 5)
{
    torso_ROTATE_FRAMEA[3]   = 17;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_TORSO == 5)
{
    torso_ROTATE_FRAMEB[3]   = 0;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    torso_ROTATE_FRAMEB[3]   = 10;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
}
if(setSelection_HIPS == 5)
{
    hips_ROTATE_FRAMEA[3]   = 2;
    hips_ROTATE_FRAMEA[0]   = 0;
    hips_ROTATE_FRAMEA[1]   = 1;
    hips_ROTATE_FRAMEA[2]   = 0;
   if(SelectionCount_HIPS == 5)
{
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
     else 
    {
    hips_ROTATE_FRAMEB[3]   = 2;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;
}
}
if(mainBodyPosition_setSelection == 6)
{
    mainBodyPosition_MOVE_FRAMEA[0]     = -0.002;
    mainBodyPosition_MOVE_FRAMEA[1]     = -0.089;
    mainBodyPosition_MOVE_FRAMEA[2]     = 3.49246e-009;
    mainBodyPosition_MOVE_FRAMEB[0]     = 0.003;
    mainBodyPosition_MOVE_FRAMEB[1]     = -0.001;
    mainBodyPosition_MOVE_FRAMEB[2]     = 0.003;
}
if(setSelection_LEFT_ARM == 6)
{    leftUpperArm_ROTATE_FRAMEA[3]   = 23;
    leftUpperArm_ROTATE_FRAMEA[0]   = 1;
    leftUpperArm_ROTATE_FRAMEA[1]   = 0;
    leftUpperArm_ROTATE_FRAMEA[2]   = 0;
    leftUpperArm_ROTATE_FRAMEB[3]   = 0;
    leftUpperArm_ROTATE_FRAMEB[0]   = 1;
    leftUpperArm_ROTATE_FRAMEB[1]   = 0;
    leftUpperArm_ROTATE_FRAMEB[2]   = 0;
    leftLowerArm_ROTATE_FRAMEA[3]   = 7;
    leftLowerArm_ROTATE_FRAMEA[0]   = 1;
    leftLowerArm_ROTATE_FRAMEA[1]   = 0;
    leftLowerArm_ROTATE_FRAMEA[2]   = 0;
    leftLowerArm_ROTATE_FRAMEB[3]   = 0;
    leftLowerArm_ROTATE_FRAMEB[0]   = 1;
    leftLowerArm_ROTATE_FRAMEB[1]   = 0;
    leftLowerArm_ROTATE_FRAMEB[2]   = 0;
    leftHand_ROTATE_FRAMEA[3]   = 0;
    leftHand_ROTATE_FRAMEA[0]   = 1;
    leftHand_ROTATE_FRAMEA[1]   = 0;
    leftHand_ROTATE_FRAMEA[2]   = 0;
    leftHand_ROTATE_FRAMEB[3]   = 0;
    leftHand_ROTATE_FRAMEB[0]   = 1;
    leftHand_ROTATE_FRAMEB[1]   = 0;
    leftHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_RIGHT_ARM == 6)
{    rightUpperArm_ROTATE_FRAMEA[3]   = 29;
    rightUpperArm_ROTATE_FRAMEA[0]   = 1;
    rightUpperArm_ROTATE_FRAMEA[1]   = 0;
    rightUpperArm_ROTATE_FRAMEA[2]   = 0;
    rightUpperArm_ROTATE_FRAMEB[3]   = 0;
    rightUpperArm_ROTATE_FRAMEB[0]   = 1;
    rightUpperArm_ROTATE_FRAMEB[1]   = 0;
    rightUpperArm_ROTATE_FRAMEB[2]   = 0;
    rightLowerArm_ROTATE_FRAMEA[3]   = -3;
    rightLowerArm_ROTATE_FRAMEA[0]   = 1;
    rightLowerArm_ROTATE_FRAMEA[1]   = 0;
    rightLowerArm_ROTATE_FRAMEA[2]   = 0;
    rightLowerArm_ROTATE_FRAMEB[3]   = 0;
    rightLowerArm_ROTATE_FRAMEB[0]   = 1;
    rightLowerArm_ROTATE_FRAMEB[1]   = 0;
    rightLowerArm_ROTATE_FRAMEB[2]   = 0;
    rightHand_ROTATE_FRAMEA[3]   = -1;
    rightHand_ROTATE_FRAMEA[0]   = 1;
    rightHand_ROTATE_FRAMEA[1]   = 0;
    rightHand_ROTATE_FRAMEA[2]   = 0;
    rightHand_ROTATE_FRAMEB[3]   = 0;
    rightHand_ROTATE_FRAMEB[0]   = 1;
    rightHand_ROTATE_FRAMEB[1]   = 0;
    rightHand_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_LEFT_LEG == 6)
{    leftUpperLeg_ROTATE_FRAMEA[3]   = -44;
    leftUpperLeg_ROTATE_FRAMEA[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEA[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEA[2]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[3]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[0]   = 1;
    leftUpperLeg_ROTATE_FRAMEB[1]   = 0;
    leftUpperLeg_ROTATE_FRAMEB[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[3]   = 66;
    leftLowerLeg_ROTATE_FRAMEA[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEA[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEA[2]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[3]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[0]   = 1;
    leftLowerLeg_ROTATE_FRAMEB[1]   = 0;
    leftLowerLeg_ROTATE_FRAMEB[2]   = 0;
    leftFoot_ROTATE_FRAMEA[3]       = -11;
    leftFoot_ROTATE_FRAMEA[0]       = 1;
    leftFoot_ROTATE_FRAMEA[1]       = 0;
    leftFoot_ROTATE_FRAMEA[2]       = 0;
    leftFoot_ROTATE_FRAMEB[3]       = 0;
    leftFoot_ROTATE_FRAMEB[0]       = 1;
    leftFoot_ROTATE_FRAMEB[1]       = 0;
    leftFoot_ROTATE_FRAMEB[2]       = 0;
}
if(setSelection_RIGHT_LEG == 6)
{    rightUpperLeg_ROTATE_FRAMEA[3]   = -46;
    rightUpperLeg_ROTATE_FRAMEA[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEA[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEA[2]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[3]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[0]   = 1;
    rightUpperLeg_ROTATE_FRAMEB[1]   = 0;
    rightUpperLeg_ROTATE_FRAMEB[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[3]   = 67;
    rightLowerLeg_ROTATE_FRAMEA[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEA[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEA[2]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[3]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[0]   = 1;
    rightLowerLeg_ROTATE_FRAMEB[1]   = 0;
    rightLowerLeg_ROTATE_FRAMEB[2]   = 0;
    rightFoot_ROTATE_FRAMEA[3]   = -5;
    rightFoot_ROTATE_FRAMEA[0]   = 1;
    rightFoot_ROTATE_FRAMEA[1]   = 0;
    rightFoot_ROTATE_FRAMEA[2]   = 0;
    rightFoot_ROTATE_FRAMEB[3]   = 0;
    rightFoot_ROTATE_FRAMEB[0]   = 1;
    rightFoot_ROTATE_FRAMEB[1]   = 0;
    rightFoot_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HEAD == 6)
{
    head_ROTATE_FRAMEA[3]   = -1;
    head_ROTATE_FRAMEA[0]   = 0.280001;
    head_ROTATE_FRAMEA[1]   = 1e-006;
    head_ROTATE_FRAMEA[2]   = 1e-006;
    head_ROTATE_FRAMEB[3]   = 4;
    head_ROTATE_FRAMEB[0]   = 0;
    head_ROTATE_FRAMEB[1]   = 1;
    head_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_TORSO == 6)
{
    torso_ROTATE_FRAMEA[3]   = 10;
    torso_ROTATE_FRAMEA[0]   = 1;
    torso_ROTATE_FRAMEA[1]   = 0;
    torso_ROTATE_FRAMEA[2]   = 0;
    torso_ROTATE_FRAMEB[3]   = 0;
    torso_ROTATE_FRAMEB[0]   = 1;
    torso_ROTATE_FRAMEB[1]   = 0;
    torso_ROTATE_FRAMEB[2]   = 0;
}
if(setSelection_HIPS == 6)
{
    hips_ROTATE_FRAMEA[3]   = 2;
    hips_ROTATE_FRAMEA[0]   = 0;
    hips_ROTATE_FRAMEA[1]   = 1;
    hips_ROTATE_FRAMEA[2]   = 0;
    hips_ROTATE_FRAMEB[3]   = 0;
    hips_ROTATE_FRAMEB[0]   = 0;
    hips_ROTATE_FRAMEB[1]   = 1;
    hips_ROTATE_FRAMEB[2]   = 0;

}
