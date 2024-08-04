
void drawC3() {
    //c3 has been segmented into 11 basic shapes for building structure, each code group represents one of these parts

    //2
    glPushMatrix();
    translate(0, 0, 0);
    rotatex(90);
    rotatez(30);
    hexagonal_prism(2, 2);
    glPopMatrix();


    //4
    glPushMatrix();
    translate(2.75, 0.25, 0);
    cuboid(2, 2.5, 2);
    glPopMatrix();

    //5
    glPushMatrix();
    translate(4.75, 0.25, 0);
    cuboid(2, 2.5, 6);
    glPopMatrix();

    //1
    glPushMatrix();
    translate(-1.36, 0.25, 2.36);
    rotatey(-30);
    cuboid(2, 2.5, 2);
    glPopMatrix();

    //3
    glPushMatrix();
    translate(-1.41, 0.25, -2.33);
    rotatey(30);
    cuboid(2, 2.5, 2);
    glPopMatrix();
    
}
