#include <iostream>
#include <vector>
#include <bullet/btBulletDynamicsCommon.h>

class Ragdoll {
public:
    Ragdoll(btDynamicsWorld* world) : world_(world) {
        // create a ragdoll with a head, torso, two arms and two legs
        createHead();
        createTorso();
        createArm();
        createArm();
        createLeg();
        createLeg();

        // join the ragdoll parts together
        join(head_, torso_, btVector3(0, 1, 0), btVector3(0, 0.5, 0));
        join(torso_, left_arm_, btVector3(-0.5, 0, 0), btVector3(0, 0.5, 0));
        join(torso_, right_arm_, btVector3(0.5, 0, 0), btVector3(0, 0.5, 0));
        join(torso_, left_leg_, btVector3(-0.2, -0.5, 0), btVector3(0, 0.5, 0));
        join(torso_, right_leg_, btVector3(0.2, -0.5, 0), btVector3(0, 0.5, 0));
    }

    void update() {
        // apply forces to the ragdoll
        // ...
    }

private:
    void createHead() {
        btCollisionShape* shape = new btSphereShape(0.2);
        btDefaultMotionState* state = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 1, 0)));
        btRigidBody::btRigidBodyConstructionInfo info(1, state, shape);
        head_ = new btRigidBody(info);
        world_->addRigidBody(head_);
    }

    void createTorso() {
        btCollisionShape* shape = new btBoxShape(btVector3(0.2, 0.5, 0.1));
        btDefaultMotionState* state = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0.5, 0)));
        btRigidBody::btRigidBodyConstructionInfo info(1, state, shape);
        torso_ = new btRigidBody(info);
        world_->addRigidBody(torso_);
    }

    void createArm() {
        btCollisionShape* shape = new btCapsuleShape(0.1, 0.5);
        btDefaultMotionState* state = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3
