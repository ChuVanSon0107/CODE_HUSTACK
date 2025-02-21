push_back(u);
    }

    // Duyệt cây từ đỉnh 1
    dfs(2);

    // Kết quả là max giữa việc chọn hoặc không chọn gốc
    cout << max(dp[2][0], dp[2][1]) << endl;

    return 0;
}
