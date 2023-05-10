cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME poker_game)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp suitENUM.h scoresENUM.h rankENUM.h Deck.h Deck.cpp CardHandScorer.h CardHandScorer.cpp CardHand.cpp Card.cpp PlayerHand.cpp PlayerHand.h cardsSFML.cpp ranksENUM.h PokerBoard.cpp PokerBoard.h ApplyRotation.cpp ApplyRotation.h MouseEvents.cpp MouseEvents.h Flop.cpp Flop.h Turn.cpp Turn.h River.cpp River.h Check.cpp Check.h Font.cpp Images.h Images.cpp Fold.cpp Fold.h Raise.cpp Raise.h TransformButton.cpp TransformButton.h Call.cpp Call.h PokerChip.cpp PokerChip.h Money.cpp Money.h PlayerIcon.cpp PlayerIcon.h Default.cpp Default.h RunGame.cpp RunGame.h Poker.cpp Poker.h Game.cpp Game.h ShadeColor.h ShadeColor.cpp StartMenu.cpp StartMenu.h Outcome.cpp Outcome.h pokerScoreDriver.cpp pokerScoreDriver.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()