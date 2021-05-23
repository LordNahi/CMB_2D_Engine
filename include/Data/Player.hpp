namespace Data::Player
{
    /**
     * TODO: It would be prefereable to use enum classes, I wanted
     * to be able to use enum values as keys for animations in our
     * map but getting a perfect typesafe solution that I wanted
     * was slowing me down, this will be another job to come back to.
     */

    enum class AnimationState
    {
        Idle,
        Walk,
        Attack
    };
}