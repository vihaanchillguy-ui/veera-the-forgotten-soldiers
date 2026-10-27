#include "VeeraGameMode.h"
#include "VeeraCharacter.h"

AVeeraGameMode::AVeeraGameMode()
{
    DefaultPawnClass = AVeeraCharacter::StaticClass();
}
