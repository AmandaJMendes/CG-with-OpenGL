
void drawC3() {
    //c3 has been segmented into 11 basic shapes for building structure, each code group represents one of these parts

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

    //2 oficial
    glPushMatrix();
    translate(0.0f, 0.0f, 0.0f);
    rotatex(-90);
    rotatez(-90);
    drawTruncatedTriangularPrism(topVertices, bottomVertices, 2);
    glPopMatrix();

    //2 claraboia
    // glPushMatrix();
    // translate(0, 1.5, 0);
    // rotatex(90);
    // rotatez(30);
    // hexagonal_prism(0.5, 0.2);
    // glPopMatrix();

    //4
    glPushMatrix();
    translate(2.15f, 0.0f, 0.0f);
    cuboid(2.0f, 2.5f, 2.0f);
    glPopMatrix();

    //5
    glPushMatrix();
    translate(4.15f, 0.0f, 0.0f);
    cuboid(2.0f, 2.5f, 6.0f);
    glPopMatrix();

    //6
    glPushMatrix();
    translate(3.15f, 0.0f, -3.0f);
    rotatex(-90);
    rotatez(-90);
    right_angle_triangular_prism(1.0f, 2.0f, 2.5f);
    glPopMatrix();

    //7
    glPushMatrix();
    translate(3.15f, 0.0f, 3.0f);
    rotatex(90);
    rotatez(-90);
    right_angle_triangular_prism(1.0f, 2.0f, 2.5f);
    glPopMatrix();

    //8 
    glPushMatrix();
    rotatey(26.57f);
    translate(2.15f, 0.0f, 6.1f);
    //rotatey(26.57);
    cuboid(2.24f, 2.5f, 2.24f);
    glPopMatrix();

    //9
    glPushMatrix();
    rotatey(-26.57f);
    translate(2.15f, 0.0f, -6.1f);
    cuboid(2.24f, 2.5f, 2.24f);
    glPopMatrix();

     //10
    glPushMatrix();
    rotatey(26.57f);
    translate(2.63f, 0.0f, 7.7f);
    //rotatey(26.57);
    cuboid(1.3f, 2.0f, 1.0f);
    glPopMatrix();

    //11
    glPushMatrix();
    rotatey(-26.57f);
    translate(2.63f, 0.0f, -7.7f);
    cuboid(1.3f, 2.0f, 1.0f);
    glPopMatrix();

    //1
    glPushMatrix();
    translate(-0.7f, 0.0f, 1.6f);
    rotatey(-27.0f);
    cuboid(2.0f, 2.5f, 2.0f);
    glPopMatrix();

    //3
    glPushMatrix();
    translate(-0.7f, 0.0f, -1.6f);
    rotatey(27.0f);
    cuboid(2.0f, 2.5f, 2.0f);
    glPopMatrix();
    
}
