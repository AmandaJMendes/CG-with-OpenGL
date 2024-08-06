
void drawC3() {
    //c3 has been segmented into 11 basic shapes for building structure, each code group represents one of these parts

    //2
    // glPushMatrix();
    // translate(0, 0, 0);
    // rotatex(90);
    // rotatez(30);
    // hexagonal_prism(2, 2.5);
    // glPopMatrix();

    float topVertices[6][3] = {
        {1.0f, 1.2f, 0.0f},
        {-1.0f, 1.2f, 0.0f},
        {-1.2f, 0.6f, 0.0f}, 
        {-0.3f, -1.2f, 0.0f},
        {0.3f, -1.2f, 0.0f}, 
        {1.2f, 0.6f, 0.0f}
    };
    float bottomVertices[6][3] = {
        {1.0f, 1.2f, 0.0f},
        {-1.0f, 1.2f, 0.0f},
        {-1.2f, 0.6f, 0.0f},
        {-0.3f, -1.2f, 0.0f},
        {0.3f, -1.2f, 0.0f},
        {1.2f, 0.6f, 0.0f}
    };

    float height = 2.0f;

    //2 oficial
    glPushMatrix();
    translate(0, 0, 0);
    rotatex(90);
    rotatez(-90);
    drawTruncatedTriangularPrism(topVertices, bottomVertices, height);
    glPopMatrix();

    //4
    glPushMatrix();
    translate(2.15, 0.25, 0);
    cuboid(2, 2.5, 2);
    glPopMatrix();

    //5
    glPushMatrix();
    translate(4.15, 0.25, 0);
    cuboid(2, 2.5, 6);
    glPopMatrix();

    //6
    glPushMatrix();
    translate(3.15, 0.25, -3);
    rotatex(-90);
    rotatez(-90);
    right_angle_triangular_prism(1, 2, 2.5);
    glPopMatrix();

    //7
    glPushMatrix();
    translate(3.15, 0.25, 3);
    rotatex(90);
    rotatez(-90);
    right_angle_triangular_prism(1, 2, 2.5);
    glPopMatrix();

    //8 
    glPushMatrix();
    rotatey(26.57);
    translate(2.15, 0.25, 6.1);
    //rotatey(26.57);
    cuboid(2.24, 2.5, 2.24);
    glPopMatrix();

    //9
    glPushMatrix();
    rotatey(-26.57);
    translate(2.15, 0.25, -6.1);
    cuboid(2.24, 2.5, 2.24);
    glPopMatrix();

     //10
    glPushMatrix();
    rotatey(26.57);
    translate(2.63, 0.25, 7.9);
    //rotatey(26.57);
    cuboid(1.3, 2.5, 1.5);
    glPopMatrix();

    //11
    glPushMatrix();
    rotatey(-26.57);
    translate(2.63, 0.25, -7.9);
    cuboid(1.3, 2.5, 1.5);
    glPopMatrix();

    //1
    glPushMatrix();
    translate(-0.7, 0.25, 1.6);
    rotatey(-27);
    cuboid(2, 2.5, 2);
    glPopMatrix();

    //3
    glPushMatrix();
    translate(-0.7, 0.25, -1.6);
    rotatey(27);
    cuboid(2, 2.5, 2);
    glPopMatrix();
    
}
