glGenBuffers(1, &gaussianBlurVerticalPass_vboID);
glBindBuffer(GL_ARRAY_BUFFER, gaussianBlurVerticalPass_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(gaussianBlurVerticalPass_VERT) + sizeof(gaussianBlurVerticalPass_NORM) + sizeof(gaussianBlurVerticalPass_TEX), 0, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(gaussianBlurVerticalPass_VERT), gaussianBlurVerticalPass_VERT);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(gaussianBlurVerticalPass_VERT),  sizeof(gaussianBlurVerticalPass_NORM), gaussianBlurVerticalPass_NORM);
glBufferSubData(GL_ARRAY_BUFFER,    sizeof(gaussianBlurVerticalPass_VERT) + sizeof(gaussianBlurVerticalPass_NORM), sizeof(gaussianBlurVerticalPass_TEX), gaussianBlurVerticalPass_TEX);


    //loadTexture("_MODEL_FOLDERS_/gaussianBlurVerticalPass/gaussianBlurVerticalPass_DOT3.bmp",   normalMap[301]);
    //loadTexture("_MODEL_FOLDERS_/gaussianBlurVerticalPass/gaussianBlurVerticalPass.jpg",        textureMap[301]);
    //loadTexture("_MODEL_FOLDERS_/gaussianBlurVerticalPass/gaussianBlurVerticalPass_BUMP.jpg", specularMap[301]);
