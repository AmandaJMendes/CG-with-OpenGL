void island(){
    glColor3f(0.0, 0.0, 1.0);

    glPushMatrix();
    glTranslatef(0, -10, 0);
    cuboid(20, 20, 20);
    glPopMatrix();

    glRotatef(90, 1, 0, 0);
    glColor3f(0.71, 0.40, 0.165);
    cylinder(4, 0.2);
    glTranslatef(0, 0, -1.1);
    glColor3f(0.647, 0.165, 0.165);
    cylinder(0.2, 4);

    glTranslatef(0, 0, -2);
    glColor3f(0, 0.5, 0);
    elipse(2, 0.1, M_PI);
    for (float angle = 60; angle <= 360; angle+=60){
        elipse(2, 0.5, M_PI);
        glRotatef(30, 0, 0, 1);
    }
    elipse(2, 0.1, M_PI);

    glTranslatef(0, 0, -0.05);
    elipse(2, 0.1, M_PI);
    for (float angle = 60; angle <= 360; angle+=60){
        elipse(2, 0.5, M_PI);
        glRotatef(30, 0, 0, 1);
    }
    elipse(2, 0.1, M_PI);
}