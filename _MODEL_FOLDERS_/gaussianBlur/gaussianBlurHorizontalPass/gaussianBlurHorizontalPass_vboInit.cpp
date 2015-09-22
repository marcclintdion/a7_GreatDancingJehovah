glGenBuffers(1, &gaussianBlurHorizontalPass_vboID);
glBindBuffer(GL_ARRAY_BUFFER, gaussianBlurHorizontalPass_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(gaussianBlurHorizontalPass_VERT) + sizeof(gaussianBlurHorizontalPass_NORM) + sizeof(gaussianBlurHorizontalPass_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(gaussianBlurHorizontalPass_VERT), gaussianBlurHorizontalPass_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(gaussianBlurHorizontalPass_VERT),  sizeof(gaussianBlurHorizontalPass_NORM), gaussianBlurHorizontalPass_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(gaussianBlurHorizontalPass_VERT) + sizeof(gaussianBlurHorizontalPass_NORM), sizeof(gaussianBlurHorizontalPass_TEX), gaussianBlurHorizontalPass_TEX);


    //loadTexture("_MODEL_FOLDERS_/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_DOT3.bmp",   normalMap[300]);
    //loadTexture("_MODEL_FOLDERS_/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass.jpg",        textureMap[300]);
    //loadTexture("_MODEL_FOLDERS_/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_BUMP.jpg", specularMap[300]);
