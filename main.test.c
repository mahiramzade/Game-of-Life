#include<stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/Basic.h>
#include "life.h"

CU_ErrorCode clean_and_exit()
{
    CU_cleanup_registry();
    return CU_get_error();
}

void testGetAliveNeighboursCountClipped()
{
    Game *game = G_new(3, 3);
    game->board[0][0] = 1;
    game->board[0][1] = 1;
    game->board[0][2] = 1;
    game->board[1][0] = 0;
    game->board[1][1] = 1;
    game->board[1][2] = 1;
    game->board[2][0] = 1;
    game->board[2][1] = 0;
    game->board[2][2] = 1;

    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 0, 0, 1), 2);
    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 0, 1, 1), 4);
    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 1, 1, 1), 6);
    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 2, 0, 1), 1);

    free(game);
}

void testGetAliveNeighboursCountCircular()
{
    Game *game = G_new(3, 3);
    game->board[0][0] = 1;
    game->board[0][1] = 1;
    game->board[0][2] = 1;
    game->board[1][0] = 0;
    game->board[1][1] = 1;
    game->board[1][2] = 1;
    game->board[2][0] = 1;
    game->board[2][1] = 0;
    game->board[2][2] = 1;

    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 0, 0, 0), 6);
    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 0, 1, 0), 6);
    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 1, 1, 0), 6);
    CU_ASSERT_EQUAL(_getAliveNeighbours(game, 2, 0, 0), 6);

    free(game);
}

void testNextGenerationClipped()
{
    Game *game = G_new(3, 3);
    game->board[0][0] = 1;
    game->board[0][1] = 1;
    game->board[0][2] = 1;
    game->board[1][0] = 0;
    game->board[1][1] = 0;
    game->board[1][2] = 0;
    game->board[2][0] = 0;
    game->board[2][1] = 0;
    game->board[2][2] = 0;
    G_live(game, 1);

    CU_ASSERT_EQUAL(game->board[0][0], 0);
    CU_ASSERT_EQUAL(game->board[0][1], 1);
    CU_ASSERT_EQUAL(game->board[0][2], 0);
    CU_ASSERT_EQUAL(game->board[1][0], 0);
    CU_ASSERT_EQUAL(game->board[1][1], 1);
    CU_ASSERT_EQUAL(game->board[1][2], 0);
    CU_ASSERT_EQUAL(game->board[2][0], 0);
    CU_ASSERT_EQUAL(game->board[2][1], 0);
    CU_ASSERT_EQUAL(game->board[2][2], 0);

    free(game);
}

void testNextGenerationCircular()
{
    Game *game = G_new(3, 3);
    game->board[0][0] = 1;
    game->board[0][1] = 1;
    game->board[0][2] = 1;
    game->board[1][0] = 0;
    game->board[1][1] = 0;
    game->board[1][2] = 0;
    game->board[2][0] = 0;
    game->board[2][1] = 0;
    game->board[2][2] = 0;
    G_live(game, 0);

    CU_ASSERT_EQUAL(game->board[0][0], 1);
    CU_ASSERT_EQUAL(game->board[0][1], 1);
    CU_ASSERT_EQUAL(game->board[0][2], 1);
    CU_ASSERT_EQUAL(game->board[1][0], 1);
    CU_ASSERT_EQUAL(game->board[1][1], 1);
    CU_ASSERT_EQUAL(game->board[1][2], 1);
    CU_ASSERT_EQUAL(game->board[2][0], 1);
    CU_ASSERT_EQUAL(game->board[2][1], 1);
    CU_ASSERT_EQUAL(game->board[2][2], 1);

    free(game);
}

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("Game of Life", NULL, NULL);

    if (!suite)
        return clean_and_exit();

    if (!CU_add_test(suite, "Test getAliveNeighbours clipped", testGetAliveNeighboursCountClipped))
        return clean_and_exit();
    if (!CU_add_test(suite, "Test getAliveNeighbours circular", testGetAliveNeighboursCountCircular))
        return clean_and_exit();
    if (!CU_add_test(suite, "Test testNextGenerationClipped clipped", testNextGenerationClipped))
        return clean_and_exit();
    if (!CU_add_test(suite, "Test testNextGenerationCircular circular", testNextGenerationCircular))
        return clean_and_exit();

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();

    return CU_get_error();
}